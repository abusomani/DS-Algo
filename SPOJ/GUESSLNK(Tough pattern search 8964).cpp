//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
/*
http://www.spoj.com/problems/GUESSING/393434000000/ : 425429

http://www.spoj.com/problems/GUESSING/393434124367/
http://www.spoj.com/problems/GUESSING/456102000000/
http://www.spoj.com/problems/GUESSING/456102123456/
http://www.spoj.com/problems/GUESSING/111111456102/
http://www.spoj.com/problems/GUESSING/111111111111/
http://www.spoj.com/problems/GUESSING/123456123456/

*/
#include <bits/stdc++.h>
using namespace std;

#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

typedef long long ll;
const ll MOD = 1000000007;

int main()
{
    fastio;
    //freopen('input.txt','r',stdin);
    //freopen('output.txt','w',stdout);
    string url;
    // url format : http://www.spoj.com/problems/GUESSING/XXXXXXYYYYYY/
    int pos = 38;

    while (getline(cin, url))
    {
        if (url.empty())
            break;

        int seed = stoi(url.substr(pos, 6));
        int answer = ((seed % 1000) * 1000) + (seed / 1000) - 8964; // 303240 => seed | 231339
        answer = (answer + 1000000) % 1000000;

        string stringGuess = url.substr(pos + 6, 6);
        string stringAnswer = to_string(answer);

        while (stringAnswer.size() < 6)
            stringAnswer = "0" + stringAnswer;

        int a = 0, b = 0;
        for (int i = 0; i < stringGuess.size(); i++)
        {
            if (stringAnswer[i] == stringGuess[i])
                a++;
            for (int j = 0; j < stringAnswer.size(); j++)
            {
                if (i != j and stringAnswer[j] == stringGuess[i])
                    b++;
            }
        }
        cout << a << "A" << b << "B" << endl;
    }

    return 0;
}
// END OF SOURCE CODE