#include<stdio.h>
#define MAX 100

int StringMatch(char[], char[], char[], char[]);
int main() {
	char s[MAX], p[MAX], r[MAX], final[MAX];
	int found;

	printf("Enter Source String \n");
	gets(s);
	printf("Enter Pattern String \n");
	gets(p);
	printf("Enter Replace String \n");
	gets(r);

	found = StringMatch(s, p, r, final);
	if (found == 1) {
		printf("The Final String : \n");
		puts(final);
	} else {
		printf("Search string Not Found \n");
	}
	return 0;
}

int StringMatch(char s[], char p[], char r[], char f[]) {
	//i - source index, j - pattern index, k - index replace, t - final found
	int i, j, k, m, t;
	int found = 0;
	j = m = i = t = 0;
	while (s[i] != '\0') {
		if (s[m++] == p[j++]) { // check for matching
			if (p[j] == '\0') { // pattern found
				//copy replace string in final string
				for (k = 0; r[k] != '\0'; k++, t++)
					f[t] = r[k];
				j = 0;
				i = m;
				found = 1;

			}
		} else {
			f[t++] = s[i++];
			m = i;
			j = 0;
		}
	}
	return found;
}
