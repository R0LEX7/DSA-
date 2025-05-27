#include <bits/stdc++.h>
using namespace std;

class BitFunctions{
    private:
    int n;

    public:
    BitFunctions(int n) {this->n = n;};

    /* int to binary */
    string intToBinary(int x){
        string res = "";

        while(x > 1){
            if(x&1) res.push_back('1');
            else res.push_back('0');

            x = x >> 1;
        }

        if(x == 1) res.push_back('1');

        reverse(res.begin() , res.end());

        return res.size() == 0? "0000" : res;
    }

    /* binary to int */
    int binaryToInt(string s){
        int n = 0 , p2 = 1;

        for(int i = s.size() - 1 ; i >= 0 ; --i){
            if(s[i] == '1'){
                n += p2;
            }

            p2 *= 2;

        }
        return n;

    }

    /* check if ith bit is set or not */
    bool isBitSet1(int x , int i){
        int one = 1 << i;

        return x&one;
    }
    bool isBitSet2(int x , int i){
        int one = 1;

        return (x >> i)&one;
    }

    /* swap two numbers */
    void swapUsingBitOp(int& a , int& b){
        a = a^b;
        b = a^b;
        a = a^b;
    }

    /* to set the ith bit */

    int setTheBit(int x , int i){
        return x|(1<<i);
    }

    /* to clear the ith bit*/
    int clearTheBit(int x , int i){
        return x&(~(1<<i));
    }

    /* toggle the ith bit*/
    int toggleTheBit(int x , int i){
        return x^(1<<i);
    }

    /* remove the last set bit*/

    int removeLastSetBit(int x){
        return x&(x-1);
    }

    /* to check if a num is a pow of 2*/
    bool isPowOf2(int x){
        return ((x&(x-1)) == 0);
    }

    /* count the set bits*/
    // tc -> o(no. of bits)
    int countTheSetBits1(int x){
        int cnt = 0;

        while(x != 0){
            if(x&1) cnt++;

            x = x>>1;
        }
        return cnt;
    }
    // better version tc = o(k) : k -> no. of set bits
    int countTheSetBits2(int x){
        int cnt = 0;

        while(x != 0){
            x = x&(x-1);
            cnt++;
        }
        return cnt;
    }

};








int main(){

    int n = 23;

    BitFunctions bf(n);

    string  s = "1011";

    cout<<bf.intToBinary(n)<<endl;

    cout<<bf.binaryToInt(s)<<endl;

    cout<<bf.isBitSet1(13 , 2)<<endl;
    cout<<bf.isBitSet1(13 , 1)<<endl;
    cout<<bf.isBitSet2(13 , 1)<<endl;
    cout<<bf.isBitSet2(13 , 0)<<endl;

    int a = 9 , b = 112;

    bf.swapUsingBitOp(a , b);

    cout<<a<<" "<<b<<endl;

    cout<<bf.intToBinary(bf.setTheBit(9 , 1))<<endl;
    cout<<bf.intToBinary(bf.clearTheBit(13,2))<<endl;
    cout<<"toggling"<<endl;
    int tog = bf.toggleTheBit(13,2);
    cout<<bf.intToBinary(tog)<<endl;
    cout<<bf.intToBinary(bf.toggleTheBit(tog,2))<<endl;
    cout<<"removing last bits"<<bf.intToBinary(bf.removeLastSetBit(8))<<endl;
    cout<<bf.isPowOf2(16)<<endl;

    cout<<"no of bits1 -> "<< bf.countTheSetBits1(9)<<endl;
    cout<<"no of bits2 -> "<< bf.countTheSetBits2(13)<<endl;



    return 0;
}
