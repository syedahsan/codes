#!/usr/bin/ruby


class Exited < Exception

        attr_reader :error_code

        def initialize(error_code, error_message)
                super(error_message)
                @error_code = error_code
        end
end

class Monitor

        attr_reader :status
        def initialize(cmd, mode = 'r')
                @cmd = cmd
                @mode = mode
        end

        def monitor()
                begin
                        pipe = IO.popen(@cmd, @mode)
                        puts "Starting #{@cmd}."
                        pid, @status = waitpid(pipe.pid)
                rescue Exited => e
                        puts "#{@cmd}: #{e.message}. Restarting.."
                        retry
                rescue Interrupt, SystemExit => e
                        puts "System Exit received. Exiting"
                end
        end

        private
        def waitpid(process_pid)
                pid, @status = Process.waitpid2(process_pid)
                raise Exited.new(1, "Process Exited")
        end

end

begin
        process = Monitor.new(ARGV[0])
        process.monitor()
rescue Exception => e
        puts "Usage: ./monitor.rb [program name]"
end
