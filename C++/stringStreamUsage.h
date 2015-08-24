	stringstream is;
	is<<"123"<<"abc";  //while input, add " " as delimiter if not exists between words 
	cout<<is.str()<<endl;//output 123abc
	string result;
	getline(is,result); //result = 124abc;
	int a1;
	string b;
	is>>a1>>b;   //output util delimiter " ", a= 123, b = abc
	cout<<a1<<" "<<b<<endl; //output 123 abc