#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;

struct Result { int
low, high, sum;
};

struct Result maxSubArrayWithConstraint(int resource[], int n, int constraint) {
int start = 0, end = 0; int current_sum = 0; int max_sum = -1;
int best_start = -1, best_end = -1;

while (end &lt; n) {
current_sum += resource[end];

while (current_sum &gt; constraint &amp;&amp; start &lt;= end) {
current_sum -= resource[start]; start++;
}

if (current_sum &lt;= constraint &amp;&amp; current_sum &gt; max_sum) {
max_sum = current_sum;
best_start = start;
best_end = end;
}

end++;
}

struct Result res;
if (max_sum == -1) {
res.low = res.high = res.sum = -1;
} else {
res.low = best_start;
res.high = best_end;
res.sum = max_sum;
}
return res;
}

int main() {
int resource[] = {2, 1, 3, 4};
int constraint = 5;
int n = sizeof(resource) / sizeof(resource[0]);

struct Result result = maxSubArrayWithConstraint(resource, n, constraint);
if (result.sum == -1) {
printf(&quot;No subarray found under the given limit.\n&quot;);
} else {
printf(&quot;Subarray starts at index %d and ends at index %d.\n&quot;, result.low,
result.high);
printf(&quot;Total sum of subarray is %d.\n&quot;, result.sum);
printf(&quot;The subarray values are: &quot;); for (int i =
result.low; i &lt;= result.high; i++) { printf(&quot;%d &quot;,
resource[i]);
}
printf(&quot;\n&quot;);
}
return 0;
}
