// Zerojudge a063: subsequence reversal
struct Treap{
	Treap *lc, *rc;
	int pri, sz, val;
	bool tag;
	Treap (int x) {
		lc = rc = NULL;
		pri = rand();
		sz = 1;
		val = x;
		tag = 0;
	}
};
inline int size(Treap* t) {
	return t ? t->sz : 0;
}
inline void pull(Treap* t) {
	t->sz = size(t->lc) + 1 + size(t->rc);
}
void push(Treap* t) {
	if (t->tag) {
		swap(t->lc, t->rc);
		if (t->lc) t->lc->tag = !t->lc->tag;
		if (t->rc) t->rc->tag = !t->rc->tag;
		t->tag = 0;
	}
}
Treap* merge(Treap* a, Treap* b) {
	if (!a || !b) return a ? a : b;
	if (a->pri > b->pri) {
		push(a);
		a->rc = merge(a->rc, b);
		pull(a);
		return a;
	}
	else {
		push(b);
		b->lc = merge(a, b->lc);
		pull(b);
		return b;
	}
}
void split(Treap* t, int k, Treap *&a, Treap *&b) {
	if (!t) a = b = NULL;
	else {
		push(t);
		if(size(t->lc) + 1 <= k) {
			a = t;
			split(t->rc, k - size(t->lc) - 1, a->rc, b);
			pull(a);
		}
		else {
			b = t;
			split(t->lc, k, a, b->lc);
			pull(b);
		}
	}
}
void output(Treap* t) {
	push(t);
	if (t->lc) output(t->lc);
	cout<<t->val<<" ";
	if (t->rc) output(t->rc);
}
main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m; cin>>n>>m;
	Treap* t = NULL;
	for (int i = 1; i <= n; i++) t = merge(t, new Treap(i));
	while (m--) {
		int l, r; cin>>l>>r;
		Treap *tl, *tr;
		split(t, l - 1, tl, t);
		split(t, r - l + 1, t, tr);
		t->tag = !t->tag;
		t = merge(merge(tl, t), tr);
	}
	output(t);
	cout<<'\n';
}
