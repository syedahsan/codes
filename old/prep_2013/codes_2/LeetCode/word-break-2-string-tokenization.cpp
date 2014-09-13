/**
 * WORD-BREAK-II
 *
 * http://oj.leetcode.com/problems/word-break-ii/
 */

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_set>

using namespace std;

/**
 * Solution class
 */
class Solution {

        private:
                map< string, vector<string> > memoized;
        public:
                vector<string> wordBreak(string s, unordered_set<string> &dict);
                vector<string> simpleWordBreak(string s, unordered_set<string> &dict);
                string singleWordBreak(string s, unordered_set<string> &dict);
};

/**
 * wordBreak method which solves the problem
 * for one of the available outcomes.
 *
 * @returns a tokenized string separated by space;
 *          null if string cannot be tokenized
 */
string
Solution::singleWordBreak(string s, unordered_set<string> &dict) {
        if (s.empty() || (dict.find(s) != dict.end())) {
                return s;
        }
        for (int i = 0; i < s.size(); ++i) {
                string prefix = s.substr(0, i+1);
                if (dict.find(prefix) != dict.end()) {
                        string suffix = singleWordBreak(s.substr(i+1, string::npos), dict);
                        if (!suffix.empty()) {
                                return prefix + " " + suffix;
                        }
                }
        }
        return string();
}

/**
 * Simple wordBreak method to tokenize a string in all possible
 * combinations. Uses recursive strategy and backtracking to
 * solve the problem
 *
 * @returns a vector of all possible tokenized varations.
 */
vector<string>
Solution::simpleWordBreak(string s, unordered_set<string> &dict) {
        vector<string> words;
        words.clear();
        if (s.empty()) {
                return words;
        } else {
                for (int i = 0; i < s.size(); ++i) {
                        string prefix = s.substr(0, i+1);
                        if (dict.find(prefix) != dict.end()) {
                                if (i == s.size() - 1) {
                                        words.push_back(prefix);
                                } else {
                                        vector<string> suffixes = simpleWordBreak(s.substr(i+1, string::npos), dict);
                                        if (!suffixes.empty()) {
                                                for (int j = 0; j < suffixes.size(); ++j) {
                                                        words.push_back(prefix + " " + suffixes[j]);
                                                }
                                        }
                                }
                        }
                }
        }
        return words;
}

/**
 * wordBreak method to tokenize a string in all possible
 * combinations. Uses memoization for faster convergence.
 *
 * @returns a vector of all possible tokenized varations.
 */
vector<string>
Solution::wordBreak(string s, unordered_set<string> &dict) {
        vector<string> words;
        words.clear();
        if (s.empty()) {
                return words;
        } else {
                if (memoized.find(s) != memoized.end()){
                        return memoized.find(s)->second;
                }
                for (int i = 0; i < s.size(); ++i) {
                        string prefix = s.substr(0, i+1);
                        if (dict.find(prefix) != dict.end()) {
                                if (i == s.size() - 1) {
                                        words.push_back(prefix);
                                } else {
                                        vector<string> suffixes = wordBreak(s.substr(i+1, string::npos), dict);
                                        if (!suffixes.empty()) {
                                                for (int j = 0; j < suffixes.size(); ++j) {
                                                        words.push_back(prefix + " " + suffixes[j]);
                                                }
                                        }
                                }
                        }
                }
        }
        memoized[s] = words;
        return words;
}


int
main() {
        //unordered_set<string> dict = {"cat", "cats", "and", "sand", "dog"};
        unordered_set<string> dict = {"cat", "cats", "and", "dog"};
        string s = "catsanddog";
        Solution sol;

        vector<string> tokenized = sol.wordBreak(s, dict);
        //vector<string> tokenized = sol.simpleWordBreak(s, dict);
        for (vector<string>::const_iterator it = tokenized.begin();
                        it != tokenized.end(); ++it) {
                cout << *it << endl;
        }

        cout << "Single: " << endl;
        string tokens = sol.singleWordBreak(s, dict);
        cout << tokens << endl;
        /*
        unordered_set<string> dict = {"kfomka","hecagbngambii","anobmnikj","c","nnkmfelneemfgcl","ah","bgomgohl","lcbjbg","ebjfoiddndih","hjknoamjbfhckb","eioldlijmmla","nbekmcnakif","fgahmihodolmhbi","gnjfe","hk","b","jbfgm","ecojceoaejkkoed","cemodhmbcmgl","j","gdcnjj","kolaijoicbc","liibjjcini","lmbenj","eklingemgdjncaa","m","hkh","fblb","fk","nnfkfanaga","eldjml","iejn","gbmjfdooeeko","jafogijka","ngnfggojmhclkjd","bfagnfclg","imkeobcdidiifbm","ogeo","gicjog","cjnibenelm","ogoloc","edciifkaff","kbeeg","nebn","jdd","aeojhclmdn","dilbhl","dkk","bgmck","ohgkefkadonafg","labem","fheoglj","gkcanacfjfhogjc","eglkcddd","lelelihakeh","hhjijfiodfi","enehbibnhfjd","gkm","ggj","ag","hhhjogk","lllicdhihn","goakjjnk","lhbn","fhheedadamlnedh","bin","cl","ggjljjjf","fdcdaobhlhgj","nijlf","i","gaemagobjfc","dg","g","jhlelodgeekj","hcimohlni","fdoiohikhacgb","k","doiaigclm","bdfaoncbhfkdbjd","f","jaikbciac","cjgadmfoodmba","molokllh","gfkngeebnggo","lahd","n","ehfngoc","lejfcee","kofhmoh","cgda","de","kljnicikjeh","edomdbibhif","jehdkgmmofihdi","hifcjkloebel","gcghgbemjege","kobhhefbbb","aaikgaolhllhlm","akg","kmmikgkhnn","dnamfhaf","mjhj","ifadcgmgjaa","acnjehgkflgkd","bjj","maihjn","ojakklhl","ign","jhd","kndkhbebgh","amljjfeahcdlfdg","fnboolobch","gcclgcoaojc","kfokbbkllmcd","fec","dljma","noa","cfjie","fohhemkka","bfaldajf","nbk","kmbnjoalnhki","ccieabbnlhbjmj","nmacelialookal","hdlefnbmgklo","bfbblofk","doohocnadd","klmed","e","hkkcmbljlojkghm","jjiadlgf","ogadjhambjikce","bglghjndlk","gackokkbhj","oofohdogb","leiolllnjj","edekdnibja","gjhglilocif","ccfnfjalchc","gl","ihee","cfgccdmecem","mdmcdgjelhgk","laboglchdhbk","ajmiim","cebhalkngloae","hgohednmkahdi","ddiecjnkmgbbei","ajaengmcdlbk","kgg","ndchkjdn","heklaamafiomea","ehg","imelcifnhkae","hcgadilb","elndjcodnhcc","nkjd","gjnfkogkjeobo","eolega","lm","jddfkfbbbhia","cddmfeckheeo","bfnmaalmjdb","fbcg","ko","mojfj","kk","bbljjnnikdhg","l","calbc","mkekn","ejlhdk","hkebdiebecf","emhelbbda","mlba","ckjmih","odfacclfl","lgfjjbgookmnoe","begnkogf","gakojeblk","bfflcmdko","cfdclljcg","ho","fo","acmi","oemknmffgcio","mlkhk","kfhkndmdojhidg","ckfcibmnikn","dgoecamdliaeeoa","ocealkbbec","kbmmihb","ncikad","hi","nccjbnldneijc","hgiccigeehmdl","dlfmjhmioa","kmff","gfhkd","okiamg","ekdbamm","fc","neg","cfmo","ccgahikbbl","khhoc","elbg","cbghbacjbfm","jkagbmfgemjfg","ijceidhhajmja","imibemhdg","ja","idkfd","ndogdkjjkf","fhic","ooajkki","fdnjhh","ba","jdlnidngkfffbmi","jddjfnnjoidcnm","kghljjikbacd","idllbbn","d","mgkajbnjedeiee","fbllleanknmoomb","lom","kofjmmjm","mcdlbglonin","gcnboanh","fggii","fdkbmic","bbiln","cdjcjhonjgiagkb","kooenbeoongcle","cecnlfbaanckdkj","fejlmog","fanekdneoaammb","maojbcegdamn","bcmanmjdeabdo","amloj","adgoej","jh","fhf","cogdljlgek","o","joeiajlioggj","oncal","lbgg","elainnbffk","hbdi","femcanllndoh","ke","hmib","nagfahhljh","ibifdlfeechcbal","knec","oegfcghlgalcnno","abiefmjldmln","mlfglgni","jkofhjeb","ifjbneblfldjel","nahhcimkjhjgb","cdgkbn","nnklfbeecgedie","gmllmjbodhgllc","hogollongjo","fmoinacebll","fkngbganmh","jgdblmhlmfij","fkkdjknahamcfb","aieakdokibj","hddlcdiailhd","iajhmg","jenocgo","embdib","dghbmljjogka","bahcggjgmlf","fb","jldkcfom","mfi","kdkke","odhbl","jin","kcjmkggcmnami","kofig","bid","ohnohi","fcbojdgoaoa","dj","ifkbmbod","dhdedohlghk","nmkeakohicfdjf","ahbifnnoaldgbj","egldeibiinoac","iehfhjjjmil","bmeimi","ombngooicknel","lfdkngobmik","ifjcjkfnmgjcnmi","fmf","aoeaa","an","ffgddcjblehhggo","hijfdcchdilcl","hacbaamkhblnkk","najefebghcbkjfl","hcnnlogjfmmjcma","njgcogemlnohl","ihejh","ej","ofn","ggcklj","omah","hg","obk","giig","cklna","lihaiollfnem","ionlnlhjckf","cfdlijnmgjoebl","dloehimen","acggkacahfhkdne","iecd","gn","odgbnalk","ahfhcd","dghlag","bchfe","dldblmnbifnmlo","cffhbijal","dbddifnojfibha","mhh","cjjol","fed","bhcnf","ciiibbedklnnk","ikniooicmm","ejf","ammeennkcdgbjco","jmhmd","cek","bjbhcmda","kfjmhbf","chjmmnea","ifccifn","naedmco","iohchafbega","kjejfhbco","anlhhhhg"};
        string s = "fohhemkkaecojceoaejkkoedkofhmohkcjmkggcmnami";
        Solution sol;

        cout << sol.singleWordBreak(s, dict) << endl;
*/
        return 0;
}       

