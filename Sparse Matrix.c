#include<stdio.h>

void accept(int m, int n, int a[10][10]){
	printf("Enter values:\n");
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			scanf("%d", &a[i][j]);
		}
	}
}

void display(int m, int n, int a[10][10]){
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void add(int a[10][10], int b[10][10], int m1, int n1, int m2, int n2){
	int c[10][10];
	for (int i = 0; i < m1; i++){
		for (int j = 0; j < n1; j++){
			c[i][j] = a[i][j] + b[i][j];
		}
	}
	display(m1,n1,c);
}

void sub(int a[10][10], int b[10][10], int m1, int n1, int m2, int n2){
	int c[10][10];
	for (int i = 0; i < m1; i++){
		for (int j = 0; j < n1; j++){
			c[i][j] = a[i][j] - b[i][j];
		}
	}
	display(m1,n1,c);
}

void mul(int a[10][10], int b[10][10], int m1 ,int n1, int m2, int n2){
	int c[10][10] = {0};
	for(int i = 0; i < m1; i++){
		for(int j= 0; j<n2; j++){
			for(int k = 0; k<n1; k++) c[i][j] += a[i][k] * b[k][j];
		}
	}
	display(m1,n2,c);
}

void trans(int a[10][10], int m, int n){
	int c[10][10];
	for(int i = 0; i < m; i++){
		for(int j =0; j < n; j++){
			c[j][i] = a[i][j];
		}
	}
	display(n,m,c);
}


void compact(int m, int n, int A[10][10], int B[10][10]) {
    B[0][0]=m;
    B[0][1]=n;
    int k=1;
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (A[i][j]) {
                B[k][0]=i;
                B[k][1]=j;
                B[k++][2]=A[i][j];
            }
        }
    }
    B[0][2]=--k;
}

void sTrans(int a[10][10]){
	int b[10][10];
	int m = a[0][0],n =  a[0][1] ,t = a[0][2];
	b[0][0] = m, b[0][1] = n,b[0][2] = t;
	int q=1;
	
	for(int col = 0; col<=n;col++){
		for(int p = 1; p<=t;p++){
			if (a[p][1] == col){
				b[q][0] = a[p][1];
				b[q][1] = a[p][0];
				b[q++][2] = a[p][2];
			}
		}
	}
	display(t+1, 3, b);
}

void fTrans(int a[10][10]){
	int b[10][10];
	int j, m = a[0][0],n =  a[0][1] ,t = a[0][2];
	b[0][0] = m, b[0][1] = n,b[0][2] = t;
	int pos[10] = {1}, s[10] = {0};
	for (int i = 0; i< t; i++) s[a[i][1]]++;
	for(int i = 1; i <= n; i++) pos[i] = pos[i-1] + s[i-1];
	for(int i = 1; i <= t; i++){
		j = a[i][1];
		b[pos[j]][0] = a[i][1];
		b[pos[j]][1] = a[i][0];
		b[pos[j]++][2] = a[i][2];
	}
	display(t+1, 3,b);
}

int sparseChecker(int m, int n, int a[10][10]){
	int  tot = m*n, nz = 0;
	for(int i = 0; i<tot; i++) if (*(*a + i)) nz++;
	if(nz<=tot) return 1;
	return 0;
}

int main(){
	int m1,n1, m2, n2, ch;
	printf("Dimensions 1: ");
	scanf("%d%d",&m1,&n1);
	printf("Dimensions 2 (enter '0 0' if array 2 is not required): ");
	scanf("%d%d",&m2,&n2);
	int a[10][10], b[10][10], com[10][10];
	

	accept(m1,n1,a);
	display(m1,n1,a);
	
	if(m2&&n2){
		accept(m2,n2,b);
		display(m2,n2,b);
		
		while(1){
			printf("Enter choice:\n1. Add\n2. Subtract\n3. Multiply\n4. Transpose a\n5. Exit\n");
			scanf("%d", &ch);
			switch(ch){
				case 1: if((m1-m2)||(n1-n2)) printf("INVALID");
					else sub(a,b,m1,n1, m2, n2); break;
				case 2: if((m1-m2)||(n1-n2)) printf("INVALID");
					else sub(a,b,m1,n1, m2, n2); break;
				case 3: if(m2!=n1){printf("INVALID");}
					else mul(a,b,m1,n1,m2,n2); break;
				case 4: trans(a,m1,n1); break;
				case 5: return 0;
			}
		}
	}
	
	int aIsSparse = sparseChecker(m1,n1,a);
	
	while(aIsSparse){
		printf("Enter choice:\n1. Compact form\n2. Simple transpose\n3. Fast transpose\n4. Exit\n");
		scanf("%d", &ch);
		compact(m1,n1, a, com);
		switch(ch){
			case 1: display(com[0][2]+1, 3, com);break;
			case 2: sTrans(com); break;
			case 3: fTrans(com); break;
			case 4: return 0;
		}
	}	
}
