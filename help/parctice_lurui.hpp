//
// Created by pip on 19-3-10.
//
#include <bits/stdc++.h>

using namespace std;

/*
#include <bits/stdc++.h>

using namespace std;

int main() {

}

 ///////////////////////begin--------------------------------

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) {
        InputStream inputStream = System.in;
        InputStreamReader inputStreamReader = new InputStreamReader(inputStream);
        BufferedReader bufferReader = new BufferedReader(inputStreamReader);

        //Get source string
        String srcStr = null;
        try{
            srcStr = bufferReader.readLine();
        }catch(IOException e){
            e.printStackTrace();
        }
        //Get destination string
        String dstStr = null;
        try{
            dstStr = bufferReader.readLine();
        }catch(IOException e){
            e.printStackTrace();
        }

        //Display the result
        System.out.println(getEditDistance(srcStr, dstStr));

        try{
            bufferReader.close();
            inputStreamReader.close();
            inputStream.close();
        }catch(IOException e){
            e.printStackTrace();
        }
	}

	public static int getEditDistance(String srcStr, String dstStr){
		int m = srcStr.length();
		int n = dstStr.length();
		//use one dimension array to represent two dimension
		//Initializing...
		int d[] = new int[(m + 1) * (n + 1)];
		for(int i = 0;i <= m;i++)
			d[i * (n + 1)] = i;
		for(int i = 0;i <= n;i++)
			d[i] = i;

		//Dynamic Programming...
		for(int i = 1; i <= m;i++){
			for(int j = 1; j <= n;j++){
				int modifyDis = d[(i - 1) * (n + 1) + (j - 1)]
				          + (srcStr.charAt(i - 1) == dstStr.charAt(j - 1) ? 0 : 1);
				int addDis = d[(i - 1) * (n + 1) + j] + 1;
				int deleteDis = d[i * (n + 1) + (j - 1)] + 1;
				d[i * (n + 1) + j] = Min(modifyDis, addDis, deleteDis);
			}
		}

		//Display Result
//		System.out.println("Result Array: ");
//		for(int i = 0; i <= m;i++){
//			for(int j = 0; j <= n;j++){
//				System.out.print("\t" + d[i * (n + 1) + j]);
//			}
//			System.out.println();
//		}

		return d[m * (n + 1) + n];
	}

	public static int Min(int a, int b, int c){
		int result = a > b ? b : a;
		return result > c ? c : result;
	}
}


  ///////////////////////end--------------------------------
*/

//===================  begin-2 ===================
#include <bits/stdc++.h>

using namespace std;


int test_01() {
    long n, ret = 1, j = 0;
    cin >> n;
    if(n == 0) {
        cout << 1;
        return 0;
    }
    for (long i = 1; i <= n; ++i) {
        j = i;
        while (j % 100000 == 0) { // 清除末尾的0
            j /= 100000;
        }
        j = j % 100000;


        ret = ret * j;
        while (ret % 100000 == 0) { // 清除末尾的0
            ret /= 100000;
        }
        ret = ret % 100000;
    }

    while (ret % 10 == 0) { // 清除末尾的0
        ret /= 10;
    }
    cout << ret % 10;

    return 0;
}
/*
#include<cstdio>
#include<cstring>
#define maxn 10000

int Last_Digit(char *buf)
{
    const int mod[20] = {1,1,2,6,4,2,2,4,2,8,4,4,8,4,6,8,8,6,8,2};
    int len = strlen(buf),a[maxn],ret = 1;
    if(len == 1)
    {
        return mod[buf[0]-'0'];
    }
    for(int i = 0;i < len;i++)
    {
        a[i] = buf[len-1-i] - '0';
    }
    for(;len != 0;len -= !a[len-1])
    {
        ret = ret*mod[a[1]%2*10 + a[0]]%5;
        for(int c = 0,i = len-1;i >= 0;i--)
        {
            c = c*10 + a[i];
            a[i] = c/5;
            c %= 5;
        }
    }
    return ret + ret %2*5;
}

int main()
{
    char buf[maxn];
    while(~scanf("%s",buf))
    {
        int ans = Last_Digit(buf);
        printf("%d\n",ans);
    }
}
 * */

//===================  end-2 ===================
void test() {
    test_01();
}