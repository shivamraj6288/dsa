string pftoin(string pfexp){
	stack <string> tpf;
	for (int i=0; i<pfexp.length(); i++){
		if (pfexp[i]=='e'){
			tpf.push("e");
		}
		else {
			string a=tpf.top();
			tpf.pop();
			string b=tpf.top();
			tpf.pop();
			string c=b+pfexp[i]+a;
			tpf.push(c);

		}
	}

	return tpf.top();
}

int f1steps(){
	int check=-1;
	int rs=0;
	for (int i=0; i<inexp.length(); i++){
		if (check==-1){
			switch (inexp[i]){
				case '*':
					check=0;
					break;
				case '+':
					check=1;
					break;

			}

		}
		else if (check==1 && inexp[i]=='*'){
			check=0;

		}
		else if (check==0 && inexp[i]=='+'){
			check=1;
			rs++;
		}
		else if (check==0 && i==inexp.length()-1){
			rs++;
		}

	}
	return ++rs;
}
