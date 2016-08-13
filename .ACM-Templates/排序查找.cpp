//三分 求函数极大值
const double EPS = 1e-9;
double TS(double l, double r) {
  while (r - l > EPS) {
    double mid1 = l + (r - l) / 3.0, mid2 = r - (r - l) / 3.0;
    if (calc(mid1) > calc(mid2)) { r = mid2; }
    else { l = mid1; }
  }
  return l;
}
//归并排序 求逆序数
ll cnt;
void mergeSort(int a[], int l, int r) {
  if (l >= r) { return; }
  int mid = (l + r) >> 1;
  mergeSort(a, l, mid);
  mergeSort(a, mid + 1, r);
  vector<int> res(r - l + 1);
  int i = l, j = mid + 1, k = 0;
  while (i <= mid && j <= r) {
    if (a[i] > a[j]) { res[k++] = a[j++]; cnt += mid + 1 - i; }
    else { res[k++] = a[i++]; }
  }
  while (i <= mid) { res[k++] = a[i++]; }
  while (j <= r) { res[k++] = a[j++]; }
  for (k = l; k <= r; k++) { a[k] = res[k - l]; }
}
//快排
void quickSort(int a[], int l, int r) {
  if (l >= r) { return; }
  int i = l, j = r, v = a[l];
  while (i < j) {
    while (i < j && a[j] >= v) { j--; }
    a[i] = a[j];
    while (i < j && a[i] <= v) { i++; }
    a[j] = a[i];
  }
  a[i] = v;
  quickSort(a, l, i - 1);
  quickSort(a, i + 1, r);
}
