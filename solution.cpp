#include "solution.h"
#include <queue>

using namespace sol1183;
using namespace std;

/* takeaways
   - it's hard to understand without using an example
   - use a 3x3 matrix as an example
     x x x
     x x x
     x x x
   - we extend it a bit so it becomes a 4x4 matrix,
     where i means imaginary
     x x x i
     x x x i
     x x x i
     i i i i
   - let's focus on the sqaure on the right upper corner
     the imaginary sqaure:
     x i
     x i
     and the real sqaure you can form(kind of flip the imaginary sqaure):
     x x
     x x
     - if you think about it, the i's actually
       represent the left side x's. The left side
       x's are overlapped with other squares, so
       we won't put ones there if we can. Just
       like i is imaginary, we can't put ones there

*/

int Solution::maxOnes(int w, int h, int sideLen, int maxOnes)
{
  auto occurs = vector<vector<int>>(sideLen, vector<int>(sideLen, 0));

  /*
    - slide the 2x2 square from left to right,
      and top to bottom without overlapping the
      previous one
    - it's fine to slide out of the matrix
      when you reach the end on the right
      or on the bottom
    - count the occurrences of each position
      - [0,0] will have the most occurrences
        followed by [1,0]
      - why?
        - they are on the edges or corners
          as we slide the 2x2 without overlapping
          the previous one
        - if you place a "one" in these positions,
          it will be less likely shared by other
          2x2 squares:
          1 x 1
          x x x
          1 x 1
  */
  for (auto i = 0; i < h; i++)
    for (auto j = 0; j < w; j++)
      occurs[i % sideLen][j % sideLen]++;

  /* max-heap by default */
  auto q = priority_queue<int, vector<int>>();

  /* populate the heap with occurrences  */
  for (auto i = 0; i < sideLen; i++)
    for (auto j = 0; j < sideLen; j++)
      q.push(occurs[i][j]);

  int total = 0;

  /* pick from the top  */
  for (int i = 0; i < maxOnes; i++)
  {
    total += q.top();
    q.pop();
  }
  return total;
}