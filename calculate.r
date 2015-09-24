n=8

maxm<-function(n){
sen=sample(1:n,n)
num=1
max=0
M=0
for(i in sen){
	s<-set()
	lis<-set(sen[1])
	m=1
	while(m<num){
		s2=set(sen[m]-1,sen[m]+1)
		s<-set_union(s,s2)
		s3=set(sen[m]+0)
		lis<-set_union(lis,s3)
		m=m+1
	} 
	if(!set_contains_element(s, as.double(i))) M=M+1

	else{
		if(set_contains_element(lis, as.double(i+1))&&set_contains_element(lis, as.double(i-1))){		
			M=M-1		}
	}
	if (max<M) max=M
	num=num+1
	}
	gc()
	return(max)
}
max=0
for(i in 1:1000){
	n=8
	max<-max+maxm(n)
}
