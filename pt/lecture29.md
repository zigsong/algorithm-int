# ch29. 그래프의 너비 우선 탐색

by | 상원

pub date | 2020.10.31.Sat

### 너비 우선 탐색

```c++
// 29.1 그래프의 너비 우선 탐색

// 그래프의 인접 리스트 표현
vector<vector<int>> adj;

vector<int> bfs(int start) {
    // 각 정점의 방문 여부, false 로 초기화
    vector<bool> discovered(adj.size(), false);
    // 방문할 정점 목록을 유지하는 큐
    queue<int> q;
    // 정점의 방문 순서
    vector<int> order;
    discovered[start] = true;
    q.push(start);
    // q 가 비어있으면 종료
    while(!q.empty()) {
        // here 에 저장하고 q에서는 삭제
        int here = q.front();
        q.pop();
        // here 를 방문한다. 방문 순서 order 에 집어 넣는다. 
        // order 를 조작하는 부분은 여기가 유일!
        order.push_back(here);
        // 모든 인접한 정점을 검사한다. adj 가 vector<vector<int>>인데, 그러면 size가 전체 정점의 갯수 아닌가?
        // 인접 리스트로 표현해야 하는 게 아닌가
        for(int i = 0; i < adj[here].size(); ++i) {
            // here -> i
            int there = adj[here][i];
            // 처음 보는 정점이면 방문 목록에 집어넣는다. not discovered
            if(!discovered[there]) {
                q.push(there);
                discovered[there] = true;
            }
        }
    }
    // 모두 끝나면 순서 반환
    return order;
}
```

1. 발견, 큐에 집어 넣음
2. 방문은 나중에

탐색 스패닝 트리는 필요 없는 부분을 쳐낸 것! 최소 경로만 남긴다



너비 우선 탐색의 시간 복잡도

- 인접 리스트 O(|V|+|E|)
- 인접 행렬 O(V^2)



너비 우선 탐색으로 풀 수 있는 문제

- 그래프에서의 최단 경로 문제



### 너비 우선 탐색과 최단거리

1. 너비 우선 탐색 스패닝 트리 계산
2. 최단 경로 계산 

``` c++
// 29.2 최단 경로를 계산하는 너비 우선 탐색

// start 에서 시작해 그래프를 너비 우선 탐색하고 시작점부터 각 정점까지의
// 최단 거리와 너비 우선 탐색 스패닝 트리를 계산하낟.
// distance[i] = start 부터 i 까지의 최단 거리
// parent[i] = 너비 우선 탐색 스패닝 트리에서 i 의 부모의 번호. 루트인 경우 자신의 번호
void bfs2(int start, vector<int>& distance, vector<int>& parent) {
    // -1 로 초기화한 parent 와 distance 벡터
    distance = vector<int>(adj.size(), -1);
    parent = vector<int>(adj.size(), -1);
    // 방문할 정점 목록을 유지하는 큐
    queue<int> q;
    distance[start] = 0;
    parent[start] = start;
    q.push(start);
    while(!q.empty()) {
        int here = q.front();
        q.pop();
        // here 의 모든 인접한 정점을 검사한다
        for(int i = 0; i < adj[here].size(); ++i) {
            int there = adj[here][i];
            // 처음 보는 정점이면 방문 목록에 집어 넣는다
            if(distance[there] == -1) {
                q.push(there);
                // start 부터 층별로 1 씩 더해진다
                distance[there] = distance[here] + 1;
                // I'm your father
                parent[there] = here;
            }
        }
    }
}

// v 부터 시작점 까지의 최단 경로를 계산
vector<int> shortestPath(int v, const vector<int>& parent) {
    // path(1, v) 가 의미하는 바?
    vector<int> path(1, v);
    // parent 가 자기 자신이면 종료
    while(parent[v] != v) {
        v = parent[v];
        path.push_back(v);
    }
    // 뒤에서부터 셌으니까 뒤집어준다
    reverse(path.begin(), path.end());
    return path;
}
```



### Sorting game

뒤집기 문제를 어떻게 그래프로?

```c++
// 29.3 Sorting Game 문제를 해결하는 너비 우선 탐색 알고리즘

// perm 을 정렬하기 위해 필요한 최소 뒤집기 연산의 수를 계산한다.
int bfs(const vector<int>& perm) {
    int n = perm.size();
    // 목표 정점을 미리 계산한다
    vector<int> sorted = perm;
    sort(sorted.begin(), sorted.end());
    // 방문 목록(큐)과 시작점부터 각 정점까지의 거리
    queue<vector<int> > q;
    map<vector<int>, int> distance;
    // 시작점을 큐에 넣는다.
    distance[perm] = 0;
    q.push(perm);
    while(!q.empty()) {
        // 이번엔 벡터가 들어간다는 점이 다르다.
        vector<int> here = q.front();
        q.pop();

        // 목표 정점을 발견했으면 곧장 종료한다.
        if(here == sorted) return distance[here];
        int cost = distance[here];
        // 가능한 모든 부분 구간을 뒤집어 본다.
        for(int i = 0; i < n; ++i) {
            // 왜 i + 2 지?
            for(int j = i + 2; j <= n; ++j){
                reverse(here.begin() + i, here.begin() + j);
                if(distance.count(here) == 0) {
                    distance[here] = cost + 1;
                    q.push(here);
                }
                reverse(here.begin() + i, here.begin() + j);
            }
        }
    }
    return -1;
}
```

그러나 시간이 너무 오래 걸리는 문제가 발생



```c++
// 29.4 Sorting Game 문제를 "빠르게" 해결

map<vector<int>, int> toSort;

// [0, 1, ... , n-1] 의 모든 순열에 대해 toSort() 를 계산해 저장한다.
void precalc(int n) {
    vector<int> perm(n);
    for(int i = 0; i < n; ++i) perm[i] = i;
    queue<vector<int> > q;
    q.push(perm);
    toSort[perm] = 0;
    while(!q.empty()) {
        vector<int> here = q.front();
        q.pop();
        int cost = toSort[here];
        for(int i = 0; i < n; ++i) {
            for(int j = i+2; j <=n; ++j) {
                reverse(here.begin() + i, here.begin() + j);
                if(toSort.count(here) == 0) {
                    toSort[here] = cost + 1;
                    q.push(here);
                }
                reverse(here.begin() + i, here.begin() + j);
            }
        }
    }
}

int solve(const vector<int>& perm) {
    // perm 을 [0, 1, ... , n-1] 의 순열로 반환한다.
    int n = perm.size();
    vector<int> fixed(n);

    for(int i = 0; i < n; ++i) {
        int smaller = 0;
        for(int j = 0; j < n; ++j) {
            if(perm[j] < perm[i]){
                ++smaller;
            }
        }
        fixed[i] = smaller;
    }
    return toSort[fixed]
}
```



### 15-퍼즐

```c++
	// 29.6 15-퍼즐을 해결하는 너비 우선 탐색 알고리즘

// 게임판의 상태를 표현한다.
class State {
    // 인접한 상태들의 목록을 반환한다.
    vector<State> getAdjacent() const;

    // map 에 state 를 넣기 위한 비교 연산자
    bool operator < (const State& rhs) const;
    // 종료 상태와 비교하기 위한 연산자
    bool operator == (const State& rhs) const;
};

typedef map<State, int> StateMap;
// start 에서 finish까지 가는 최단 경로의 길이를 반환한다.
int bfs(State start, State finish) {
    // 예외: start == finish 인 경우 (기저사례?)
    if(start == finish) return 0;
    // 각 정점까지의 최단 경로의 길이를 저장한다.
    StateMap c;
    // 앞으로 방문할 정점들을 저장한다.
    queue<State> q;
    q.push(start);
    c[start] = 0;
    // 너비 우선 탐색
    while(!q.empty()) {
        State here = q.front();
        q.pop();
        int cost = c[here];
        // 인접한 정점들의 번호를 얻어낸다.
        vector<State> adjacent = here.getAdjacent();
        for(int i = 0; i < adjacent.size(); ++i) {
            // 이게 의미하는 바?
            if(c.count(adjacent[i]) == 0) {
                // 답을 찾았나? 끝에 도달하면 1 더해서 return
                if(adjacent[i] == finish) return cost + 1;
                // 그렇지 않으면 cost + 1 을 저장
                c[adjacent[i]] = cost + 1;
                q.push(adjacent[i]);
            }
        }
    }
    // 답을 찾지 못한 경우
    return -1;
}
```

그러나 비효율적! 메모리와 시간 복잡도 모두 지수적으로 증가한다.



### 최단 경로 문제에서 너비 우선 탐색 대신 쓸 수 있는 방법

1. #### 양방향 탐색

   개념은 단순, 두 개의 방향에서 출발해 만나자

   ```c++
   // 29.7 15-퍼즐 문제를 해결하는 양방향 탐색 알고리즘
   
   // 15-퍼즐 문제의 상태를 표현하는 클래스
   class State;
   // x 의 부호를 반환한다
   int sgn(int x) { if(!x) return 0; return x > 0 ? 1 : -1;}
   // x 의 절대값을 1 증가시킨다.
   int incr(int x) {if(x < 0) return x - 1; return x + 1;}
   // start 에서 finish 까지 가는 최단 경로의 길이를 반환한다.
   int bidirectional(State start, State finish) {
       // 각 정점까지의 최단 경로의 길이를 저장한다.
       map<State, int> c;
       // 앞으로 방문할 정점들을 저장한다.
       queue<State> q;
       // 시작 상태와 목표 상태가 같은 경우는 예외로 처리해야 한다.
       if(start == finish) return 0;
       q.push(start); c[start] = 1;
       q.push(finish); c[finish] = -1;
       // 너비 우선 탐색
       while(!q.empty()) {
           State here = q.front();
           q.pop();
           // 인접한 상태들을 검사한다.
           vector<State> adjacent = here.getAdjacent();
           for(int i = 0; i < adjacent.size(); ++i) {
               map<State, int>::iterator it = c.find(adjacent[i]);
               if(it == c.end()) {
                   // 절댓값 1 증가
                   c[adjacent[i]] = incr(c[here])
                   q.push(adjacent[i])
               }
               // 가운데서 만난 경우
               else if(sgn(it->second) != sgn(c[here])) {
                   return abs(it->second) + abs(c[here]) - 1;
               }
           }
       }
       // 답을 찾지 못한 경우
       return -1;
   }
   ```

   

   but 역방향 간선을 찾아내기 어렵다거나, 역방향 간선이 지나치게 많은 경우에는 적절하지 않다

   or 양방향 탐색으로도 찾기 힘들만큼 최단거리가 크면?

2. #### **점점 깊어지는 탐색**

   임의로 깊이 제한 l을 설정한다

   깊이 우선 탐색으로 이보다 짧은 경로가 존재하는지 확인

   찾으면 반환, 못 찾으면 l 을 늘려서 다시 시도

   지금까지 찾아낸 최단 경로를 전역변수 best 에 저장하고, 이보다 길이가 길어지면 바로 종료하자!

   ```c++
   // 29.8 15-퍼즐 문제를 해결하는 점점 깊어지는 탐색 알고리즘
   
   // 15-퍼즐 문제의 상태를 표현하는 클래스
   class State;
   int best;
   // 깊이 우선 탐색
   void dfs(State here, const State& finish, int steps) {
       // 지금까지 구한 최적해보다 더 좋을 가능성이 없으면 버린다.
       if(steps >= best) return;
       // 목표 상태에 도달한 경우
       if(here == finish) { best = steps; return; }
       // 인접 상태들을 깊이 우선 탐색으로
       vector<State> adjacent = here.getAdjacent();
       for(int i = 0; i < adjacent.size(); ++i){
           dfs(adjacent[i], finish, steps+1);
       }
   }
   
   // 점점 깊어지는 탐색
   int ids(State start, State finish, int growthStep) {
       for(int limit = 4; ; limit += growthStep) {
           best = limit + 1;
           dfs(start, finish, 0);
           if(best <= limit) return best;
       }
       return -1;
   }
   ```



시도는 **너비우선 -> 양방향 -> 점점 깊어지는** 순으로

비트마스크?



### 하노이의 탑

```c++
// 29.9 하노이의 탑 문제를 해결하는 너비 우선 탐색 코드

const int MAX_DISCS = 12;
// 비트마스크를 사용해서 32비트 정수를 배열처럼 사용??
int get(int state, int index) {
    return (state >> (index * 2)) & 3;
}
int set(int state, int index, int value) {
    return (state & ~(3 << (index * 2))) | (value << (index * 2));
}
int c[1<<(MAX_DISCS*2)];
// discs 개의 원반이 있고, 각 원반의 시작 위치와 목표 위치가
// begin, end 에 주어질 때 최소 움직임의 수를 계산한다.
int bfs(int discs, int begin, int end) {
    if(begin == end) return 0;
    queue<int> q;
    memset(c, -1, sizeof(c));
    q.push(begin);
    c[begin] = 0;
    while(!q.empty()) {
        int here = q.front();
        q.pop();
        // 각 기둥에서 제일 위에 있는 원반의 번호를 계산한다.
        int top[4] = { -1, -1, -1, -1 };
        for(int i = discs-1; i >= 0; --i) {
            top[get(here, i)] = i;
        }
        // i번 기둥의 맨 위에 있는 원반을 j번 기둥으로 옮긴다.
        for(int i = 0; i < 4; ++i) {
            // i 번 기둥에 원반이 없으면 안된다.
            if(top[i] != -1){
                for(int j = 0; j < 4; ++j){
                    // j 번 기둥은 비어 있거나, 맨 위의 원반이 더 커야 한다.
                    if(i != j && (top[j] == -1 || top[j] > top[i])) {
                        int there = set(here, top[i], j);
                        if(c[there] != -1) continue;
                        c[there] = c[here] + 1;
                        if(there == end) return c[there];
                        q.push(there);
                    }
                }
            }
        }
    }
    return -1;
}
```

시간이 엄청 오래 걸리므로!

64층의 하노이탑을 다 옮기면 세상의 끝이 온다는 설화가 있다고 함 



```c++
// 29.10 하노이의 탑 문제를 해결하는 양방향 탐색의 구현

// x의 부호를 반환한다.
int sgn(int x) { if(!x) return 0; return x > 0 ? 1 : -1; } 
// x 의 절대값 1 증가
int incr(int x) { if(x < 0) return x-1; return x+1; }

// discs 개의 원반이 있고, 각 원반의 시작 위치와 목표 위치가
// begin, end 에 주어질 때 최소 움직임의 수를 계산한다.
int bidir(int discs, int begin, int end) {
    if(begin == end) return 0;
    queue<int> q;
    // 초기화를 0으로 한다 (부호를 기준으로 판별하므로)
    memset(c, 0, sizeof(c));
    // 정방향 탐색은 양수로, 역방향 탐색은 음수로
    q.push(begin); c[begin] = 1;
    q.push(end); c[end] = -1;
    while(!q.empty()) {
        int here = q.front();
        q.pop();
        int top[4] = { -1, -1, -1, -1 };
        for(int i - discs-1; i >= 0; --i) {
            top[get(here, i)] = i;
        }
        for(int i = 0; i < 4; ++i) {
            if(top[i] != -1) {
                for(int j = 0; j < 4; ++j) {
                    if(i != j && (top[j] == -1 || top[j] > top[i])) {
                        int there = set(here, top[i], j);
                        // 아직 방문하지 않은 정점인 경우
                        if(c[there] == 0) {
                            c[there] = incr(c[here]);
                            q.push(there);
                        }
                        // 가운데에서 만난 경우
                        else if(sgn(c[there]) != sgn(c[here])){
                            return abs(c[there]) + abs(c[here]) - 1;
                        }
                    }
                }
            }
        }
    }
    return -1;
}
```



# ch30. 최단 경로 알고리즘

각 간선에 양의 가중치가 주어진다!



다익스트라 알고리즘

​	우선 순위 큐에 정점의 번호와 지금까지 찾아낸 해당 정점까지의 최단 거리를 쌍으로 넣는다

​	최단 거리 기준으로 방문

​	이러면 너비 우선 탐색의 문제를 보완할 수 있다.(발견 순서대로 방문)

```c++
// 30.1 다익스트라의 최단 거리 알고리즘의 구현

// 정점의 개수
int V;
// 그래프의 인접 리스트. (연결된 정점 번호, 간선 가중치) 쌍을 담는다.
vector<pair<int, int> > adj[MAX_V];
vector<int> dijkstra(int src) {
    vector<int> dist(V, INF);
    dist[src] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, src));
    while(!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        // 만약 지금 꺼낸 것보다 더 짧은 경로를 알고 있다면 지금 꺼낸 것을 무시한다.
        if(dist[here] < cost) continue;
        // 인접한 정점들을 모두 검사한다.
        for(int i = 0; i < adj[here].size(); ++i) {
            int there = adj[here][i].first;
            int nextDist = cost + adj[here][i].second;
            // 더 짧은 경로를 발견하면 dist 를 갱신하고 우선순위 큐에 넣는다.
            if(dist[there]  = nextDist) {
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist, there));
            }
        }
    }
}
```



```c++
// 30.2 우선순위 큐를 사용하지 않는 다익스트라 알고리즘의 구현

vector<int> dijkstra2(int src) {
    vector<int> dist(V, INF);
    // 각 정점을 방문했는지 여부를 저장한다.
    vector<bool> visited(V, false);
    dist[src] = 0; visited[src] = false;
    while(true) {
        // 아직 방문하지 않은 정점 중 가장 가까운 정점을 찾는다.
        int closest = INF, here;
        for(int i = 0; i < V; ++i) {
            if(dist[i] < closest && !visited[i]) {
                here = i;
                closest = dist[i];
            }
        }
        if(closest == INF) break;
        // 가장 가까운 정점을 방문한다.
        visited[here] = true;
        for(int i = 0; i < adj[here].size(); ++i) {
            int there = adj[here][i].first;
            if(visited[there]) continue;
            int nextDist = dist[here] + adj[here][i].second;
            dist[there] = min(dist[there], nextDist);
        }
    }
    return dist;
}
```

