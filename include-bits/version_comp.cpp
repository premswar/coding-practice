#include<bits/stdc++.h>
using namespace std;

string getsubstring(string str) {
	
	int zindex = 0;
    cout <<	str << endl;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '.') {
			string temp = str.substr(zindex, i - zindex);
			cout<<"in forloop: "<<temp<<endl;
			if(temp.length() == 0) return "0";
			else return temp;
		}
		if (str[i] == '0' && zindex == i) zindex++;
		cout <<"I and Zindex"<< i<<"    "<<zindex<<endl;
	}
	
	string temp = str.substr(zindex, (int)str.length() - zindex);
	cout<<"after forloop: "<<temp<<endl;
	if(temp.length() == 0) return "0";
	else return temp;
	
}

string getnext(string str) {
	
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '.') {
		return str.substr(i + 1);
		}
	}
	
	return "0";
}


int solve(string V1, string V2) {
	
	while(V1 != V2) {
		
		string current1 = getsubstring(V1), current2 = getsubstring(V2);
		cout<<"current1: "<<current1<<" current2: "<<current2<<endl;
		int gap = (int)current1.length() - (int)current2.length();
		cout<<"gap: "<<gap<<endl;
		if (gap != 0) return gap > 0 ? 1 : -1;
		else if (current1 != current2) return current1 > current2 ? 1 : -1;
		V1 = getnext(V1);
		V2 = getnext(V2);
		cout<<"V1: "<<V1<<" V2: "<<V2<<endl;
	}
	
	return 0;
}

int main() {
	
	string a = "1.202.10";
	string b = "1.40.50";
	cout << solve(a, b) << endl;
}
