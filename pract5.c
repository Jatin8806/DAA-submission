#include &lt;stdio.h&gt;
#include &lt;string.h&gt;

#define MAX 100

// Build LCS tables void lcs(char x[], char y[], int m, int n,
int c[MAX][MAX], int b[MAX][MAX]) {
for (int i = 0; i &lt;= m; i++) c[i][0] = 0;
for (int j = 0; j &lt;= n; j++) c[0][j] = 0;

for (int i = 1; i &lt;= m; i++) {
for (int j = 1; j &lt;= n; j++) {
if (x[i - 1] == y[j - 1]) {
c[i][j] = c[i - 1][j - 1] + 1;

b[i][j] = 1; // Diagonal (match)
} else if (c[i - 1][j] &gt;= c[i][j - 1]) {
c[i][j] = c[i - 1][j]; b[i][j]
= 2; // Up
} else {
c[i][j] = c[i][j - 1];
b[i][j] = 3; // Left
}
}
}
printf(&quot;Length of LCS: %d\n&quot;, c[m][n]);
}

// Reconstruct and print LCS void printlcs(int
b[MAX][MAX], char x[], int i, int j) { if (i == 0 || j
== 0) return;
if (b[i][j] == 1) {
printlcs(b, x, i - 1, j - 1);
printf(&quot;%c&quot;, x[i - 1]); } else
if (b[i][j] == 2) {
printlcs(b, x, i - 1, j);

} else {
printlcs(b, x, i, j - 1);
}
}

int main() {
char x[] = &quot;AGCCCTAAGGGCTACCTAGCTT&quot;;
char y[] = &quot;GACAGCCTACAAGCGTTAGCTTG&quot;;
int m = strlen(x), n = strlen(y);
int c[MAX][MAX], b[MAX][MAX];

lcs(x, y, m, n, c, b);

printf(&quot;Longest Common Subsequence: &quot;);
printlcs(b, x, m, n);
printf(&quot;\n&quot;);

return 0;
}
