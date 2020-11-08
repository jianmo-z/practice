//
// Created by pip on 19-3-10.
//
#include <bits/stdc++.h>

using namespace std;

int test_01() {
    bool ret = false;
    string str;
    cin >> str;
    vector<bool> v(40, false);

    for(char i: str) {
        if(i >= 'a' && i <= 'z') {
            if(v[static_cast<int>(i)] == false) {
                v[static_cast<int>(i)] = true;
            } else {
                ret = true;
                break;
            }
        }
    }
    cout << (ret?"true":"false");
    return 0;
}

int test_02() {
    string str, tmp;
    vector<int> v;
    int num = 0;

    cin >> str >> num;
    str.erase(str.find('['));
    str.erase(str.find(']'));
    str.erase(str.find(' '));
    stringstream s(str);

    str.clear();
    while (getline(s, tmp, ',')) {
        v.push_back(atol(tmp.c_str()));
    }
    if (num <= v.size()) {
        for (int i = 0; i + num < v.size(); i = i + num) {
            reverse(v.begin() + i, v.begin() + i + num);
        }
    }
    if (v.size() > 0) {
        cout << "[";
        for (int i = 0; i < v.size() - 1; ++i) {
            cout << v[i] << ",";
        }
        cout << v[v.size() - 1] << "]";
    } else {
        cout << "[]";
    }
    return 0;
}

int test_03() {
    return 0;
}
void test() {
//	test_01();
//	test_02();
	test_03();
}
//
//import java.util.*;
//
//public  class Main{
//    public static void main(String[] args) {
//        Scanner scan=new Scanner(System.in);
//        Map<String,String> map=new HashMap<>();
//        int n = scan.nextInt();
//        for(int i=0;i<n;i++){
//            String str=scan.next();
//            String tmp = map.get(str);
//            if(tmp==null){
//                tmp="";
//            }
//            map.put(str,tmp+"_"+i);
//        }
//        String[] strs=new String[n];
//        for(Map.Entry<String,String> en : map.entrySet()){
//            String[] ss = en.getValue().split("_");
//            int len = en.getKey().split("/").length;
//            int x=0;
//            for(int j=0;j<ss.length;j++){
//                if("".equals(ss[j])){
//                    continue;
//                }
//                int in = Integer.valueOf(ss[j]);
//                StringBuilder sb=new StringBuilder();
//                sb.append(1);
//                if(len-1>1){
//                    for(int z=0;z<len-3;z++){
//                        sb.append(x+1);
//                    }
//                    sb.append(1);
//                }
//                strs[in]=sb.toString();
//                x++;
//            }
//        }
//        for(String sss:strs){
//            System.out.println(sss);
//        }
//    }
//}
//
//
//
//import java.util.Scanner;
//public class Main {
//    public static void main(String[] args) {
//        Scanner scan = new Scanner(System.in);
//        String str = scan.nextLine();
//        int d = scan.nextInt();
//        str = str.replace("[", "");
//        str = str.replace("]", "");
//        String[] split = str.split(",");
//        int[] arr=new int[split.length];
//        for(int i=0;i<split.length;i++){
//            arr[i]=Integer.valueOf(split[i]);
//        }
//        for(int i=0;i<arr.length;i+=d){
//            int z=i;
//            int j=i+d-1;
//            while(z<j){
//                int t=arr[z];
//                arr[z]=arr[j];
//                arr[j]=t;
//                z++;
//                j--;
//            }
//        }
//        StringBuilder sb=new StringBuilder();
//        sb.append("[");
//        for(int i=0;i<arr.length-1;i++){
//            sb.append(arr[i]+",");
//        }
//        sb.append(arr[arr.length-1]+"]");
//        System.out.println(sb.toString());
//    }
//}
