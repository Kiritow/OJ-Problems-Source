//加栈
//G++
int main() {
  int sz = 100 << 20; //100MB
  char *p = (char *)malloc(sz) + sz;
  __asm__ __volatile__(
#if __x86_64__ || __ppc64__ || _WIN64 //64-bit
    "movq %0, %%rsp\n pushq $_exit\n"
#else //32-bit
    "movl %0, %%esp\n pushl $_exit\n"
#endif
    :: "r"(p));
  //......
  exit(0);
}
//VC++ 100MB
#pragma comment(linker, "/STACK:102400000,102400000")

//位运算
//把右边连续的1变成0    | (100101111->100100000)    | x and (x+1)
//把右起第一个0变成1    | (100101111->100111111)    | x or (x+1)
//把右边连续的0变成1    | (11011000->11011111)      | x or (x-1)
//取右边连续的1         | (100101111->1111)         | (x xor (x+1)) shr 1
//去掉右起第一个1的左边 | (100101000->1000)         | x and (x xor (x-1))
//枚举i的非空子集j
for (int j = i; j; j = (j - 1) & i);

//builtin函数
int __builtin_ffs(int x);
int __builtin_ffsll(long long);
//Returns one plus the index of the least significant 1-bit of x, or if x is zero, returns zero.
int __builtin_clz(unsigned int x);
int __builtin_clzll(unsigned long long);
//Returns the number of leading 0-bits in x, starting at the most significant bit position. If x is 0, the result is undefined.
int __builtin_ctz(unsigned int x);
int __builtin_ctzll(unsigned long long);
//Returns the number of trailing 0-bits in x, starting at the least significant bit position. If x is 0, the result is undefined.
int __builtin_clrsb(int x);
int __builtin_clrsbll(long long);
//Returns the number of leading redundant sign bits in x, i.e. the number of bits following the most significant bit that are identical to it. There are no special cases for 0 or other values.
int __builtin_popcount(unsigned int x);
int __builtin_popcountll(unsigned long long);
//Returns the number of 1-bits in x.
int __builtin_parity(unsigned int x);
int __builtin_parityll(unsigned long long);
//Returns the parity of x, i.e. the number of 1-bits in x modulo 2.
uint32_t __builtin_bswap32(uint32_t x);
uint64_t __builtin_bswap64(uint64_t x);
//Returns x with the order of the bytes reversed; for example, 0xaabb becomes 0xbbaa. Byte here always means exactly 8 bits.

//rope O(log(len))
#include <ext/rope>
using namespace __gnu_cxx;

//pb_ds库
//http://gaotianyu1350.gitcafe.io/2015/02/17/pbds/
//priority_queue
//定义
//包含：ext/pb_ds/priority_queue.hpp
//声明：__gnu_pbds::priority_queue<T>
//模板参数：
//template<typename Value_Type,
//         typename Cmp_Fn = std::less<Value_Type>,
//         typename Tag = pairing_heap_tag,
//         typename Allocator = std::allocator<char>>
//class priority_queue;
//Value_Type：类型
//Cmp_Fn：自定义比较器
//Tag：堆的类型。可以是binary_heap_tag（二叉堆）binomial_heap_tag（二项堆）rc_binomial_heap_tag pairing_heap_tag（配对堆）thin_heap_tag
//Allocator：不用管
//使用
//相比STL中的priority_queue，可以
//用begin()和end()获取迭代器从而遍历
//删除单个元素void erase(point_iterator)
//增加或减少某一元素的值void modify(point_iterator, const_reference)
//合并void join(priority_queue &other)，把other合并到*this，并把other清空
//性能分析
//五种操作：push、pop、modify、erase、join
//pairing_heap_tag：push和joinO(1)，其余均摊O(logn)
//binary_heap_tag：只支持push和pop，均为均摊O(logn)
//binomial_heap_tag：push为均摊O(1)，其余为O(logn)
//rc_binomial_heap_tag：push为O(1)，其余为O(logn)
//thin_heap_tag：push为O(1)，不支持join，其余为O(logn)；但是如果只有increase_key，modify均摊O(1)
//不支持不是不能用，而是用起来很慢
//大致结论：
//对于优化Dijkstra算法，pairing_heap_tag严格快于thin_heap_tag，速度与手写数据结构相当
//线段树大法好
//binary_heap_tag在绝大多数情况下优于std::priority_queue
//pairing_heap_tag在绝大多数情况下优于binomial_heap_tag和rc_binomial_heap_tag
//只有push，pop和join操作时，binary_heap_tag速度较快
//在有modify操作时，可以考虑pairing_heap_tag，thin_heap_tag或手写数据结构

//Tree
//定义
//包含：ext/pb_ds/assoc_container.hpp和ext/pb_ds/tree_policy.hpp
//声明：__gnu_pbds::tree<Key, T>
//模板参数：
//template<typename Key,
//         typename Mapped,
//         typename Cmp_Fn = std::less<Key>,
//         typename Tag = rb_tree_tag,
//         template<typename Const_Node_Iterator,
//                  typename Node_Iterator,
//                  typename Cmp_Fn_,
//                  typename Allocator_ >
//         class Node_Update = null_tree_node_update,
//         typename Allocator = std::allocator<char>>
//class tree;
//Tag：tree的类型，可以是rb_tree_tag，splay_tree_tag，ov_tree_tag
//Node_Update：可以为空，也可以用pb_ds自带的tree_order_statistics_node_update，这样这个tree就会获得两个函数find_by_order和order_of_key
//iterator find_by_order(size_type order)：找第order + 1小的元素的迭代器，如果order太大会返回end()
//size_type order_of_key(const_key_reference r_key)：询问这个tree中有多少比r_key小的元素
//使用
//与map使用方法基本相同，包括begin()，end()，size()，empty()，clear()，find(const Key)，
//lower_bound(const Key)，upper_bound(const Key)，erase(iterator)，erase(const Key)，
//insert(const pair<Key, T>)，operator[](const Key)
//如果想改成set，只需要将第二个参数Mapped改为null_type（在4.4.0及以下版本的编译器中应用null_mapped_type）就可以了。此时迭代器指向的类型会从pair变成Key，和set几乎没有区别
//当然还有一些其他用法，如：
//void join(tree &other)：把other中所有元素移动到*this上（值域不能相交，否则会抛出异常）
//void split(const_key_reference r_key, tree &other)：清空other，然后把*this中所有大于r_key的元素移动到other
//自定义Node_Update使用方法
//自带的tree_order_statistics_node_update统计的是子树size
//稍加修改就可以统计容易合并的任意信息
//以下代码实现了区间求和
template<class Node_CItr, class Node_Itr, class Cmp_Fn, class _Alloc>
struct my_node_update {
  virtual Node_CItr node_begin()const = 0;
  virtual Node_CItr node_end()const = 0;
  typedef int metadata_type; //节点上记录的额外信息的类型
  inline void operator()(Node_Itr it, Node_CItr end_it) {
    Node_Itr l = it.get_l_child(), r = it.get_r_child();
    int left = 0, right = 0;
    if (l != end_it) { left = l.get_metadata(); }
    if (r != end_it) { right = r.get_metadata(); }
    const_cast<metadata_type &>(it.get_metadata()) = left + right + (*it)->second;
  }
  inline int prefix_sum(int x) {
    int ans = 0;
    Node_CItr it = node_begin();
    while (it != node_end()) {
      Node_CItr l = it.get_l_child(), r = it.get_r_child();
      if (Cmp_Fn()(x, (*it)->first)) { it = l; }
      else {
        ans += (*it)->second;
        if (l != node_end()) { ans += l.get_metadata(); }
        it = r;
      }
    }
    return ans;
  }
  inline int interval_sum(int l, int r) {
    return prefix_sum(r) - prefix_sum(l - 1);
  }
};
int main() {
  tree<int, int, std::less<int>, rb_tree_tag, my_node_update> T;
  T[2] = 100; T[3] = 1000; T[4] = 10000;
  printf("%d\n%d\n", T.interval_sum(3, 4), T.prefix_sum(3));
}
//注意：
//对Node_Itr可以做的事情：用get_l_child和get_r_child获取左右儿子，用两个星号（一个星号只是获取了iterator）获取节点信息，用get_metadata获取节点额外信息
//operator()的功能是将节点it的信息更新，传入的end_it表示空节点
//性能分析
//和手写数据结构差不多，rb_tree_tag要更快

//Hash
//定义
//包含：ext/pb_ds/assoc_container.hpp和ext/pb_ds/hash_policy.hpp
//声明：
//__gnu_pbds::cc_hash_table<Key, Mapped>
//__gnu_pbds::gp_hash_table<Key, Mapped>
//使用
//支持find和operator[]

//Trie
//定义
//包含：ext/pb_ds/assoc_container.hpp和ext/pb_ds/trie_policy.hpp
//声明：__gnu_pbds::trie<Key, Mapped>
//模板参数：
//template<typename Key,
//         typename Mapped,
//         typename Cmp_Fn = std::less<Key>,
//         typename Tag = pat_trie_tag,
//         template<typename Const_Node_Iterator,
//                  typename Node_Iterator,
//                  typename E_Access_Traits_,
//                  typename Allocator_>
//         class Node_Update = null_trie_node_update,
//         typename Allocator = std::allocator<char>>
//class trie;
//Key is the key type.
//Mapped is the mapped-policy, and is explained in Tutorial::Associative Containers::Associative Containers Others than Maps.
//E_Access_Traits is described in Element-Access Traits.
//Tag specifies which underlying data structure to use, and is described shortly.
//Node_Update is a policy for updating node invariants. This is described in Node Invariants.
//Allocator is an allocator type.
//功能：
//pair<const_iterator, const_iterator> prefix_range(key_const_reference)
//Finds the const iterator range corresponding to all values whose prefixes match r_key
//如果你想用这个函数，trie的模板参数得这么写trie<string, [your type here], string_trie_e_access_traits<>, pat_trie_tag, trie_prefix_search_node_update>

//List（用作multimap/multiset）
//定义
//包含：ext/pb_ds/assoc_container.hpp和ext/pb_ds/list_update_policy.hpp
//声明：__gnu_pbds::list_update<Key, Mapped>
//模板参数：
//template<typename Key,
//         typename Mapped,
//         typename Eq_Fn = std::equal_to<Key>,
//         typename Update_Policy = move_to_front_lu_policy<>,
//         typename Allocator = std::allocator<char>>
//class list_update;

//总结
//priority_queue，与STL相比支持了modify，erase和join
//tree，相当于STL中的set/map，还支持split和join，运用tree_order_statistics_node_update还支持查询rank和k小值；更可以自定义Node_Update来维护更多信息
//（目前比赛环境中）STL没有的两种hash_table
//无脑用pb_ds代替std::set/map/priority_queue不会使程序变得更慢
