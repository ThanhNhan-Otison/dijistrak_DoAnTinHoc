//Dao Thanh Nhan Mssv:DH52201133 Lop:D22_Th12
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;
int n = 5, m = 8;//n:so dinh, m: so canh
vector<pair<int, int>> adj[10];//khoi tao 1 mang vector de luu danh sach ke co trong so
const  int INF = 1e9;//khoi tao gia tri vo cung lon
int pre[100];//khoi tao mang luu dinh truoc dinh dang xet

//dinh nghia ham xuat
void xuat() {

	for (int i = 0; i < 10; i++)
	{
		if (adj[i].empty()) continue;
		else {
			cout << (char)(i + 64) << ": ";
			for (auto x : adj[i])
				cout << (char)(x.first + 64) << "|" << x.second << "->";
			cout << endl;
		}

	}
}

//dinh nghia thuat toan dijistrak
void djk(int s, int t) {
	//khoi tao mang kiem tra dinh duoc duoc xet chua co gia tri =false
	vector<bool> visited(n + 1, false);

	//khoi tao mang luu khoang cach duong di co gia tri vo cung lon
	vector <ll> d(n + 1, INF);
	d[s] = 0; pre[s] = s;

	//hang doi uu tien luu khoang cach(=key) va dinh, uu tien gia tri nho nhat(min heap)
	priority_queue<pair<int, int>, vector<pair<int, int>>,
		greater<pair<int, int>>> q;
	q.push({ 0,s });
	while (!q.empty()) {

		//chon ra dinh co k/c tu s nho nhat
		pair<int, int> top = q.top(); q.pop();
		int u = top.second;
		int kc = top.first;

		/*//if (kc > d[u]) continue;
		//relaxation: cap nhat kc tu s-> moi dinh ke voi u*/
		if (visited[u]) continue; //kiem tra dinh nay da duoc xet chua
		visited[u] = true;

		for (auto it : adj[u]) {
			int v = it.first;
			int w = it.second;
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				q.push({ d[v],v });
				pre[v] = u;//truoc v la u
			}
		}
	}
	cout << "khoang cach la duong di ngan nhat la: " << d[t];
	//khoi tao vector luu duong di ngan nhat tu dinh nguon den dinh dich
	vector<int> path;
	//kiem tra va gan dinh vao vector
	while (1) {
		path.push_back(t);
		if (t == s)break;
		t = pre[t];
	}
	cout << endl;
	//dao lai duong di do ham push_back la ham them cuoi
	reverse(begin(path), end(path));
	//xuat ra duong di ngan nhat 
	for (auto x : path)
		cout << char(x + 64) << "->";
}
int main() {
	//khoi tao danh sach ke
	adj[1].push_back({ 2,1 }); adj[1].push_back({ 3,5 }); 
	adj[2].push_back({ 1,1 }); adj[2].push_back({ 3,6 }); adj[2].push_back({ 4,2 }); adj[2].push_back({ 5,7 });
	adj[3].push_back({ 1,5 }); adj[3].push_back({ 2,6 }); adj[3].push_back({ 4,8 }); adj[3].push_back({ 5,4 });
	adj[4].push_back({ 2,2 }); adj[4].push_back({ 3,8 }); adj[4].push_back({ 5,3 });
	adj[5].push_back({ 2,7 }); adj[5].push_back({ 3,4 }); adj[5].push_back({ 4,3 });
	cout << "\nGia su ta co 5 router va 8 canh, moi router luu khoang cach (theo do thi)the hien duoi dang danh sach ke nhu sau: \n";
	xuat();
	cout << "Nhap router nguon va  router dich: \n";
	char a, b;
	cin >> a >> b;
	int s = (int)a - 64;
	int t = (int)b - 64;
	//goi ham dijistrak tim duong di ngan nhat cua 2 router
	djk(s, t);
	cout << endl;
	return 0;
}