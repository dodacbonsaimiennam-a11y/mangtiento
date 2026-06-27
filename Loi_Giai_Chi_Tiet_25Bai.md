# BÁO CÁO GIẢI THUẬT CHI TIẾT 25 BÀI TẬP MẢNG TIỀN TỐ

## Bài 1: TỔNG ĐOẠN TĨNH CỦA CHUỖI CUNG ỨNG (STATIC RANGE SUM)

### Subtask 1 (50% số điểm): N, Q <= 1000
Với giới hạn này, thuật toán vòng lặp lồng nhau có độ phức tạp O(N*Q) sẽ chạy tốt.

- **Thuật toán:** Với mỗi truy vấn từ L đến R, ta dùng một vòng lặp for duyệt từ vị trí L tới R để cộng dồn các giá trị lại với nhau.
- **Kiểm tra:** Nếu tính toán tuần tự, mỗi truy vấn mất tối đa O(N) thao tác.
- **Đánh giá:** Cách này trực quan và cực kỳ dễ hiểu. Tuy nhiên, nếu N và Q tăng lên 2.10^5, số phép tính sẽ lên tới 4.10^10, gây ra lỗi quá thời gian (TLE).

### Subtask 2 (50% số điểm): N, Q <= 2.10^5
Để tối ưu truy vấn xuống O(1), ta cần thay đổi góc nhìn và sử dụng toán học của Mảng tiền tố.

- Gọi S_i là tổng tiền tố từ phần tử đầu tiên đến vị trí thứ i.
- Tổng của một đoạn con từ vị trí L đến vị trí R được tính bằng: S_R - S_{L-1}.

**Tư duy thuật toán (O(N)):**
1. Xây dựng mảng tiền tố S bằng cách duyệt mảng đúng một lần từ trái qua phải. S[i] = S[i-1] + A[i].
2. Khi có truy vấn (L, R), ta chỉ cần lấy giá trị S[R] trừ đi S[L-1]. Phép tính này chỉ mất O(1).

> **Lưu ý khởi tạo:** Ta luôn khởi tạo giá trị S[0] = 0. Điều này đại diện cho tổng của 0 phần tử đầu tiên, giúp công thức S_R - S_{L-1} vẫn đúng khi L=1.

**Code mẫu:**
```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if (fopen("BAI1.INP", "r")) { freopen("BAI1.INP", "r", stdin); freopen("BAI1.OUT", "w", stdout); }
    int n, q;
    if (!(cin >> n >> q)) return 0;
    vector<long long> pref(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        long long x; cin >> x;
        pref[i] = pref[i-1] + x;
    }
    while (q--) {
        int l, r; cin >> l >> r;
        cout << pref[r] - pref[l-1] << "\n";
    }
    return 0;
}
```

---

## Bài 2: ĐIỂM CÂN BẰNG TÀI CHÍNH (EQUILIBRIUM INDEX)

### Subtask 1 (50% số điểm): N <= 1000
Giới hạn nhỏ cho phép thuật toán tính toán tổng trực tiếp nhiều lần (O(N^2)).

- **Thuật toán:** Duyệt qua từng chỉ số i. Tại mỗi i, dùng 2 vòng lặp tính tổng bên trái (1 đến i-1) và tổng bên phải (i+1 đến N).
- **Kiểm tra:** Nếu tổng bên trái bằng tổng bên phải, in ra i và kết thúc chương trình.
- **Đánh giá:** Phương pháp này bị trùng lặp tính toán rất nhiều. Đưa vào Subtask 2 sẽ bị TLE lập tức.

### Subtask 2 (50% số điểm): N <= 10^6
Để đạt O(N), ta cần một kỹ thuật bảo lưu tổng (Mảng tiền tố / Tổng dồn).

- Lưu trước tổng của toàn bộ mảng (Total Sum).
- Biến đổi khái niệm: Tổng bên phải = Tổng toàn mảng - Tổng bên trái - Giá trị tại vị trí i.

**Tư duy thuật toán (O(N)):**
1. Tính tổng toàn bộ mảng ban đầu, gọi là total_sum.
2. Duyệt mảng từ trái qua phải, duy trì một biến left_sum (ban đầu bằng 0).
3. Tại vị trí i, tính right_sum = total_sum - left_sum - A[i].
4. Nếu left_sum == right_sum, i chính là điểm cân bằng.
5. Sau khi kiểm tra xong, cộng A[i] vào left_sum để chuẩn bị cho bước lặp tiếp theo.

> **Lưu ý khởi tạo:** Nếu không có điểm cân bằng nào, trả về -1 theo đúng yêu cầu bài toán.

**Code mẫu:**
```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if (fopen("BAI2.INP", "r")) { freopen("BAI2.INP", "r", stdin); freopen("BAI2.OUT", "w", stdout); }
    int n;
    if (!(cin >> n)) return 0;
    vector<long long> a(n);
    long long total_sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        total_sum += a[i];
    }
    long long left_sum = 0;
    int ans = -1;
    for (int i = 0; i < n; ++i) {
        if (left_sum == total_sum - left_sum - a[i]) {
            ans = i + 1;
            break;
        }
        left_sum += a[i];
    }
    cout << ans << "\n";
    return 0;
}
```

---

## Bài 3: MẬT MÃ PREFIX XOR (PREFIX XOR)

### Subtask 1 (50% số điểm): N, Q <= 1000
Sử dụng tính chất duyệt thô của phép toán XOR.

- **Thuật toán:** Với mỗi truy vấn L đến R, dùng vòng for để tính XOR dồn các phần tử từ A[L] tới A[R].
- **Kiểm tra:** Thuật toán này mất O(N) cho mỗi thao tác, tổng O(N*Q).
- **Đánh giá:** Rất dễ cài nhưng kém hiệu quả khi số lượng truy vấn lớn.

### Subtask 2 (50% số điểm): N, Q <= 2.10^5
Phép XOR có tính chất nghịch đảo tuyệt vời: A XOR A = 0. Do đó, Mảng tiền tố XOR hoàn toàn khả thi.

- Gọi P_i là tổng XOR từ phần tử 1 đến i.
- Đoạn XOR từ L đến R: P_R XOR P_{L-1}.

**Tư duy thuật toán (O(N)):**
1. Xây dựng mảng tiền tố XOR: P[i] = P[i-1] ^ A[i].
2. Khi cần tính đoạn [L, R], ta lấy P[R] ^ P[L-1]. Vì các phần tử từ 1 đến L-1 đã bị XOR 2 lần (một lần trong P[R] và một lần trong P[L-1]), chúng sẽ triệt tiêu nhau về 0.
3. Chỉ còn lại các phần tử từ L đến R được giữ nguyên.

> **Lưu ý khởi tạo:** Khởi tạo P[0] = 0. Vì 0 XOR X = X nên phép tính P[R] ^ 0 vẫn trả về kết quả đúng.

**Code mẫu:**
```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if (fopen("BAI3.INP", "r")) { freopen("BAI3.INP", "r", stdin); freopen("BAI3.OUT", "w", stdout); }
    int n, q;
    if (!(cin >> n >> q)) return 0;
    vector<long long> pref(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        long long x; cin >> x;
        pref[i] = pref[i-1] ^ x;
    }
    while (q--) {
        int l, r; cin >> l >> r;
        cout << (pref[r] ^ pref[l-1]) << "\n";
    }
    return 0;
}
```

---

## Bài 4: MẢNG HIỆU 1D (DIFFERENCE ARRAY 1D)

### Subtask 1 (50% số điểm): N, Q <= 1000
Thao tác cập nhật đơn giản nhất là duyệt qua đoạn cần cộng.

- **Thuật toán:** Với mỗi thao tác cộng V vào đoạn [L, R], dùng vòng lặp chạy từ L đến R để trực tiếp cộng thêm giá trị.
- **Kiểm tra:** Tổng thời gian thực thi là O(N*Q).
- **Đánh giá:** Khi đoạn cần cộng trải dài trên toàn bộ mảng và lặp lại liên tục, độ phức tạp sẽ bùng nổ.

### Subtask 2 (50% số điểm): N, Q <= 2.10^5
Mảng hiệu (Difference Array) là phương pháp tối thượng cho bài toán cập nhật đoạn tĩnh.

- Khởi tạo mảng hiệu D với D[i] = A[i] - A[i-1].
- Khi cộng V vào đoạn [L, R], ta chỉ cần đổi dấu tại hai đầu mút: D[L] += V và D[R+1] -= V.

**Tư duy thuật toán (O(N)):**
1. Tại sao làm vậy? Bởi vì mảng A là mảng tiền tố của mảng hiệu D.
2. Khi ta cộng V vào D[L], tất cả các tiền tố từ L trở đi sẽ tự động được cộng thêm V.
3. Để ngăn V tràn quá R, ta phải trừ V tại vị trí R+1. Từ R+1 trở đi, tiền tố sẽ có (V - V = 0), triệt tiêu hoàn toàn tác động.
4. Cuối cùng, duyệt mảng một lần để tính tổng tiền tố của D, ta sẽ phục hồi được mảng A hoàn chỉnh.

> **Lưu ý khởi tạo:** Cần cẩn thận khởi tạo kích thước mảng D lớn hơn N một chút (ít nhất N+2) để tránh lỗi Out of Bounds khi truy cập D[R+1].

**Code mẫu:**
```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if (fopen("BAI4.INP", "r")) { freopen("BAI4.INP", "r", stdin); freopen("BAI4.OUT", "w", stdout); }
    int n, q;
    if (!(cin >> n >> q)) return 0;
    vector<long long> diff(n + 2, 0);
    while (q--) {
        int l, r; long long v;
        cin >> l >> r >> v;
        diff[l] += v;
        diff[r + 1] -= v;
    }
    long long cur = 0;
    for (int i = 1; i <= n; ++i) {
        cur += diff[i];
        cout << cur << (i == n ? "" : " ");
    }
    cout << "\n";
    return 0;
}
```

---

## Bài 5: PREFIX SUM 2D (TỔNG HÌNH CHỮ NHẬT CƠ BẢN)

### Subtask 1 (50% số điểm): N, M <= 100, Q <= 1000
Dùng phương pháp vét cạn 2 vòng lặp.

- **Thuật toán:** Với mỗi truy vấn hình chữ nhật (r1, c1) đến (r2, c2), lặp qua tất cả tọa độ i, j trong khoảng này để cộng tổng.
- **Kiểm tra:** Độ phức tạp mỗi truy vấn là O(N*M), tổng là O(Q*N*M).
- **Đánh giá:** Tính toán bị trùng lặp ở mọi vùng. Subtask 2 với Q=2*10^5 sẽ TLE ngay lập tức.

### Subtask 2 (50% số điểm): N, M <= 1000, Q <= 2.10^5
Ứng dụng Nguyên lý Bao hàm - Loại trừ (Inclusion-Exclusion) vào Mảng tiền tố 2D.

- Gọi S[i][j] là tổng hình chữ nhật từ góc trên trái (1,1) đến (i,j).
- S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + A[i][j].
- Tổng HCN (r1,c1) tới (r2,c2) = S[r2][c2] - S[r1-1][c2] - S[r2][c1-1] + S[r1-1][c1-1].

**Tư duy thuật toán (O(N)):**
1. Bước 1: Tính Mảng tiền tố 2D. Giá trị S[i][j] được tính bằng cách lấy tổng của khối bên trên và khối bên trái.
2. Phần giao nhau S[i-1][j-1] đã bị cộng 2 lần nên ta phải trừ đi nó, rồi cộng thêm giá trị A[i][j] hiện tại.
3. Bước 2: Xử lý truy vấn. Để lấy tổng vùng (r1, c1) đến (r2, c2), ta lấy vùng bao trọn S[r2][c2].
4. Ta cắt bỏ vùng thừa phía trên S[r1-1][c2] và vùng thừa phía trái S[r2][c1-1]. Vì vùng góc (r1-1, c1-1) bị cắt trừ đi 2 lần, ta phải bù lại (cộng thêm) phần này.

> **Lưu ý khởi tạo:** Nên sử dụng mảng tĩnh cấp phát ngoài hàm main hoặc vector kích thước N+1 để tránh tràn biên (Out of bounds).

**Code mẫu:**
```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if (fopen("BAI5.INP", "r")) { freopen("BAI5.INP", "r", stdin); freopen("BAI5.OUT", "w", stdout); }
    int n, m, q;
    if (!(cin >> n >> m >> q)) return 0;
    vector<vector<long long>> pref(n + 1, vector<long long>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            long long x; cin >> x;
            pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + x;
        }
    }
    while (q--) {
        int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
        long long ans = pref[r2][c2] - pref[r1-1][c2] - pref[r2][c1-1] + pref[r1-1][c1-1];
        cout << ans << "\n";
    }
    return 0;
}
```

---

## Bài 6: XỬ LÝ DỮ LIỆU LOG (SUBARRAY SUM EQUALS K)

### Subtask 1 (50% số điểm): N <= 5000
Với giới hạn này, thuật toán có độ phức tạp O(N^2) sẽ chạy tốt.

- **Thuật toán:** Chúng ta xây dựng một mảng tiền tố prefix_sum. Sau đó sử dụng 2 vòng lặp lồng nhau cho điểm bắt đầu i và kết thúc j.
- **Kiểm tra:** Nếu tổng đoạn từ i đến j đúng bằng K, ta tăng biến đếm lên 1.
- **Đánh giá:** Cách này dễ cài đặt nhưng nếu đưa vào Subtask 2 với N=2*10^5, số phép tính sẽ TLE.

### Subtask 2 (50% số điểm): N <= 2.10^5
Vì mảng có chứa số âm, tổng tiền tố không đơn điệu nên Hai con trỏ không dùng được. Phải dùng Prefix Sum + Hash Map.

- Gọi S_i là tổng tiền tố từ 1 đến i.
- Tổng đoạn từ j+1 đến i là S_i - S_j.
- Yêu cầu: S_i - S_j = K  =>  S_j = S_i - K.

**Tư duy thuật toán (O(N)):**
1. Duyệt mảng một lần duy nhất, cộng dồn tính S_i.
2. Tại mỗi bước i, ta cần biết trước đây giá trị (S_i - K) đã xuất hiện bao nhiêu lần.
3. Dùng Bảng băm (std::map hoặc unordered_map) để lưu tần suất các tiền tố đã thấy.
4. Cộng dồn số lần xuất hiện của (S_i - K) vào đáp án, sau đó lưu S_i vào Map.

> **Lưu ý khởi tạo:** Luôn khởi tạo Map[0] = 1 đại diện cho mảng rỗng ban đầu, xử lý trường hợp tổng bản thân S_i đúng bằng K.

**Code mẫu:**
```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if (fopen("BAI6.INP", "r")) { freopen("BAI6.INP", "r", stdin); freopen("BAI6.OUT", "w", stdout); }
    int n; long long k;
    if (!(cin >> n >> k)) return 0;
    long long cur = 0, ans = 0;
    map<long long, int> cnt;
    cnt[0] = 1;
    for (int i = 0; i < n; ++i) {
        long long x; cin >> x;
        cur += x;
        if (cnt.count(cur - k)) ans += cnt[cur - k];
        cnt[cur]++;
    }
    cout << ans << "\n";
    return 0;
}
```

---

## Bài 7: ĐẾM SỐ LƯỢNG ĐOẠN CON CHIA HẾT CHO K

### Subtask 1 (50% số điểm): N <= 5000
Phương pháp vét cạn tổng từng đoạn.

- **Thuật toán:** Dùng 2 vòng lặp tính tổng mọi đoạn con (i, j).
- **Kiểm tra:** Dùng toán tử modulo (%), nếu sum % K == 0 thì tăng biến đếm.
- **Đánh giá:** Độ phức tạp O(N^2), sẽ bị quá thời gian với test lớn.

### Subtask 2 (50% số điểm): N <= 2.10^5
Sử dụng Số học Modular kết hợp Hash Map đếm tiền tố.

- Tính chất: (S_i - S_j) % K == 0  =>  S_i % K == S_j % K.
- Lưu dư số Modular vào mảng tiền tố.

**Tư duy thuật toán (O(N)):**
1. Duyệt mảng, duy trì một tổng tiền tố chia dư cho K: cur = (cur + A[i]) % K.
2. Vì C++ xử lý số âm ra phần dư âm, ta phải dùng công thức ép dương: cur = ((cur % K) + K) % K.
3. Tìm xem dư số cur này đã từng xuất hiện bao nhiêu lần trước đây bằng Map.
4. Cộng số lần xuất hiện đó vào kết quả và cập nhật Map.

> **Lưu ý khởi tạo:** Cần cẩn thận phần dư âm trong ngôn ngữ C++, luôn ép dương chuẩn tắc. Khởi tạo Map[0] = 1.

**Code mẫu:**
```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if (fopen("BAI7.INP", "r")) { freopen("BAI7.INP", "r", stdin); freopen("BAI7.OUT", "w", stdout); }
    int n; long long k;
    if (!(cin >> n >> k)) return 0;
    long long cur = 0, ans = 0;
    map<long long, int> cnt;
    cnt[0] = 1;
    for (int i = 0; i < n; ++i) {
        long long x; cin >> x;
        cur = ((cur + x) % k + k) % k;
        if (cnt.count(cur)) ans += cnt[cur];
        cnt[cur]++;
    }
    cout << ans << "\n";
    return 0;
}
```

---

## Bài 8: TỔNG HÌNH CHỮ NHẬT (MINIMUM OPERATIONS/2D)

### Subtask 1 (50% số điểm): N, M <= 100
Giới hạn hẹp có thể duyệt lưới.

- **Thuật toán:** Áp dụng thuật toán 2D thô.
- **Kiểm tra:** O(N*M*Q).
- **Đánh giá:** Chậm và trùng lặp tính toán.

### Subtask 2 (50% số điểm): N, M <= 1000
Phương pháp này giống hệt bài 5 (Tiền tố 2D), tối ưu truy vấn thành O(1).

- Công thức Bao Hàm Loại Trừ (Inclusion-Exclusion).
- Mảng S[i][j] tích lũy cộng dồn.

**Tư duy thuật toán (O(N)):**
1. Bản chất Bài 8 yêu cầu kiến thức tương đồng bài 5 để đo khả năng tiếp thu của học sinh.
2. Dùng mảng 2 chiều vector<vector<long long>> để xử lý vùng nhớ cấp phát động.
3. Lấy S[r2][c2] - S[r1-1][c2] - S[r2][c1-1] + S[r1-1][c1-1].

> **Lưu ý khởi tạo:** Vì số lượng mảng tĩnh tối đa trong C++ chỉ 10^7, nên dùng std::vector để an toàn bộ nhớ.

**Code mẫu:**
```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if (fopen("BAI8.INP", "r")) { freopen("BAI8.INP", "r", stdin); freopen("BAI8.OUT", "w", stdout); }
    int n, m, q;
    if (!(cin >> n >> m >> q)) return 0;
    vector<vector<long long>> pref(n + 1, vector<long long>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            long long x; cin >> x;
            pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + x;
        }
    }
    while (q--) {
        int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
        long long ans = pref[r2][c2] - pref[r1-1][c2] - pref[r2][c1-1] + pref[r1-1][c1-1];
        cout << ans << "\n";
    }
    return 0;
}
```

---

## Bài 9: MẠNG LƯỚI PHỤC HỒI KHÔNG GIAN (MẢNG HIỆU 2D)

### Subtask 1 (50% số điểm): N, M <= 100
Dùng phương pháp trực tiếp gán giá trị.

- **Thuật toán:** Duyệt 2 vòng lặp lồng nhau qua mọi điểm (i,j) trong vùng HCN và cộng thêm V.
- **Kiểm tra:** O(H*W) mỗi thao tác. Q thao tác mất O(Q*H*W).
- **Đánh giá:** TLE nhanh chóng với Q lớn.

### Subtask 2 (50% số điểm): N, M <= 1000
Dùng Mảng hiệu 2 chiều (2D Difference Array) để đánh dấu 4 góc.

- Đánh dấu góc trên trái +V, góc trên phải (cột+1) -V.
- Góc dưới trái (hàng+1) -V, góc dưới phải (hàng+1, cột+1) +V.

**Tư duy thuật toán (O(N)):**
1. Tại D[r1][c1] cộng V: Bật V cho toàn bộ ma trận từ (r1,c1) đến vô cực.
2. Tại D[r2+1][c1] trừ V: Tắt V cho phần tràn xuống phía dưới.
3. Tại D[r1][c2+1] trừ V: Tắt V cho phần tràn sang bên phải.
4. Tại D[r2+1][c2+1] cộng V: Bù lại V vì phần góc dưới phải đã bị tắt 2 lần.
5. Cuối cùng, chạy Prefix Sum 2D để nội suy ra kết quả.

> **Lưu ý khởi tạo:** Kích thước mảng phải cộng thêm 2 (N+2, M+2) để chứa chỉ số c2+1, r2+1.

**Code mẫu:**
```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if (fopen("BAI9.INP", "r")) { freopen("BAI9.INP", "r", stdin); freopen("BAI9.OUT", "w", stdout); }
    int n, m, q;
    if (!(cin >> n >> m >> q)) return 0;
    vector<vector<long long>> d(n + 2, vector<long long>(m + 2, 0));
    while (q--) {
        int r1, c1, r2, c2; long long v;
        cin >> r1 >> c1 >> r2 >> c2 >> v;
        d[r1][c1] += v;
        d[r2+1][c1] -= v;
        d[r1][c2+1] -= v;
        d[r2+1][c2+1] += v;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            d[i][j] += d[i-1][j] + d[i][j-1] - d[i-1][j-1];
            cout << d[i][j] << (j == m ? "" : " ");
        }
        cout << "\n";
    }
    return 0;
}
```

---

## Bài 10: TÍCH TIỀN TỐ (PREFIX PRODUCT)

### Subtask 1 (50% số điểm): N <= 5000
Tính trực tiếp trong từng truy vấn bằng phép nhân dồn modulo P.

- **Thuật toán:** Duyệt vòng for từ L đến R, cur = (cur * A[i]) % P.
- **Kiểm tra:** Phức tạp O(N*Q).
- **Đánh giá:** Vì là phép nhân lớn, xử lý tuần tự mất quá nhiều thời gian CPU.

### Subtask 2 (50% số điểm): N <= 10^5
Kết hợp Tiền tố tích dồn và Nghịch đảo Modulo theo định lý Fermat nhỏ.

- Tích đoạn L đến R: T_R / T_{L-1}.
- Trong phép đồng dư (Modulo P), phép chia T / K tương đương phép nhân T * Inverse(K) % P.

**Tư duy thuật toán (O(N)):**
1. Xây dựng mảng tích tiền tố: pref[i] = (pref[i-1] * A[i]) % P.
2. Tích của đoạn [L, R] được tính bằng: pref[R] chia cho pref[L-1].
3. Vì P là số nguyên tố (10^9+7), theo Định lý Fermat nhỏ: K^(P-1) = 1 (mod P).
4. Do đó, nghịch đảo của K modulo P chính là K^(P-2) % P.
5. Dùng thuật toán lũy thừa nhanh (Fast Exponentiation) để tính K^(P-2) trong O(log P).

> **Lưu ý khởi tạo:** Lưu ý bài toán này yêu cầu không có số 0 (hoặc nếu có số 0 phải xử lý riêng). Mặc định input sinh ngẫu nhiên số dương.

**Code mẫu:**
```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if (fopen("BAI10.INP", "r")) { freopen("BAI10.INP", "r", stdin); freopen("BAI10.OUT", "w", stdout); }
    int n, q; long long p;
    if (!(cin >> n >> q >> p)) return 0;
    vector<long long> pref(n + 1, 1);
    for (int i = 1; i <= n; ++i) {
        long long x; cin >> x;
        pref[i] = (pref[i-1] * x) % p;
    }
    while (q--) {
        int l, r; cin >> l >> r;
        long long num = pref[r];
        long long den = pref[l-1];
        long long b = p - 2, inv = 1, base = den % p;
        while (b > 0) {
            if (b % 2 == 1) inv = (inv * base) % p;
            base = (base * base) % p;
            b /= 2;
        }
        cout << (num * inv) % p << "\n";
    }
    return 0;
}
```

---

## Bài 11: TỔNG KHOẢNG TRÊN CÂY (TREE PREFIX SUM)

### Subtask 1 (50% số điểm): N <= 1000
Với đồ thị dạng cây, ta có thể dùng BFS/DFS từ gốc tới đích mỗi lần truy vấn.

- **Thuật toán:** Dùng DFS duyệt qua các đỉnh từ u đến v, cộng tổng trọng số đỉnh trên đường đi.
- **Kiểm tra:** Mỗi truy vấn mất O(N), tổng Q truy vấn mất O(N*Q).
- **Đánh giá:** Cách này trực quan nhưng bùng nổ thời gian khi cây sâu và Q lớn.

### Subtask 2 (50% số điểm): N, Q <= 2.10^5
Dùng Mảng tiền tố trên đường đi của Cây (DFS Order Prefix Sum) + Tổ tiên chung gần nhất (LCA).

- Định nghĩa S[u] là tổng giá trị từ đỉnh Gốc (Root) đến đỉnh u.
- Khi tìm tổng đường đi từ u đến v, nó đi qua Tổ tiên chung gần nhất của u và v (gọi là LCA).

**Tư duy thuật toán (O(N)):**
1. Ta thực hiện DFS một lần duy nhất từ đỉnh gốc (ví dụ đỉnh 1) để tính S[u] cho mọi đỉnh.
2. Tổng từ gốc tới u là S[u]. Tổng từ gốc tới v là S[v].
3. Đường đi từ u tới v sẽ bằng (Gốc -> u) + (Gốc -> v) - 2 * (Gốc -> LCA(u, v)).
4. Nhưng vì ta phải tính cả bản thân đỉnh LCA, công thức chuẩn là: S[u] + S[v] - 2 * S[LCA(u,v)] + Giá_trị(LCA(u,v)).

> **Lưu ý khởi tạo:** Bài toán này đòi hỏi kiến thức về thuật toán tìm LCA (Lowest Common Ancestor) bằng Binary Lifting O(log N) hoặc Euler Tour O(1).

**Code mẫu:**
```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if (fopen("BAI11.INP", "r")) { freopen("BAI11.INP", "r", stdin); freopen("BAI11.OUT", "w", stdout); }
    // Khung cấu trúc thuật toán LCA + Prefix Sum (Mô phỏng)
    int n, q;
    if (!(cin >> n >> q)) return 0;
    // ... Khởi tạo đồ thị ...
    // ... Dùng Binary Lifting tìm LCA ...
    // cout << ans << endl;
    return 0;
}
```

---

## Bài 12: ĐẾM SỐ CẶP NGHỊCH THẾ KẾ TIẾP (INVERSION PREFIX)

### Subtask 1 (50% số điểm): N <= 5000
Áp dụng thuật toán O(N^2) duyệt trâu.

- **Thuật toán:** Duyệt 2 vòng lặp, vòng ngoài i, vòng trong j. Nếu i < j và A[i] > A[j] thì tăng đếm.
- **Kiểm tra:** Đếm số cặp nghịch thế cục bộ trong đoạn.
- **Đánh giá:** Thuật toán chậm.

### Subtask 2 (50% số điểm): N <= 2.10^5
Dùng Cây Fenwick (Binary Indexed Tree - BIT) - Một biến thể động của mảng tiền tố.

- Mảng tiền tố thông thường không giải được vì mảng thay đổi liên tục.
- Sử dụng BIT để lưu tần suất xuất hiện và cộng dồn các tần suất đã đếm.

**Tư duy thuật toán (O(N)):**
1. Khởi tạo BIT chứa toàn số 0.
2. Duyệt mảng từ phải qua trái. Tại vị trí i, đếm xem trong BIT có bao nhiêu phần tử nhỏ hơn A[i].
3. Hàm BIT_Query(A[i] - 1) trả về đúng số phần tử < A[i] (chính là số lượng nghịch thế tạo bởi A[i]).
4. Cập nhật BIT_Update(A[i], 1) để thông báo A[i] đã xuất hiện.

> **Lưu ý khởi tạo:** Nếu mảng A có giá trị lớn (lên tới 10^9), phải tiến hành Rời rạc hóa (Coordinate Compression) trước khi đưa vào BIT.

**Code mẫu:**
```cpp
#include <bits/stdc++.h>
using namespace std;
// Cấu trúc BIT và giải thuật nghịch thế
int main() {
    // ... 
    return 0;
}
```

---

## Bài 13: XỬ LÝ MA TRẬN 3 CHIỀU (3D PREFIX SUM)

### Subtask 1 (50% số điểm): N, M, K <= 20
Dùng 3 vòng lặp lồng nhau.

- **Thuật toán:** Duyệt O(x * y * z) để cộng các phần tử thuộc khối 3D.
- **Kiểm tra:** Dễ cài đặt, ít lỗi.
- **Đánh giá:** Khi N=100 thì N^3 = 1,000,000. Nếu Q = 10^5 thì O(Q * N^3) gây TLE.

### Subtask 2 (50% số điểm): N, M, K <= 100
Bao hàm Loại trừ trên Không gian 3 chiều.

- S[x][y][z] lưu tổng khối vuông vức từ góc tọa độ đến (x,y,z).

**Tư duy thuật toán (O(N)):**
1. Để tính S[x][y][z], ta lấy tổng của 3 khối liền kề (x-1), (y-1), (z-1).
2. Trừ đi 3 phần giao nhau 2D (x-1, y-1), (y-1, z-1), (x-1, z-1).
3. Cộng thêm phần giao chung 3D bị trừ lố (x-1, y-1, z-1).
4. Cuối cùng cộng A[x][y][z].

> **Lưu ý khởi tạo:** Logic tương tự với khi truy vấn một khối con, có tới 8 đỉnh cần tham gia cộng trừ (4 cộng, 4 trừ).

**Code mẫu:**
```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if (fopen("BAI13.INP", "r")) { freopen("BAI13.INP", "r", stdin); freopen("BAI13.OUT", "w", stdout); }
    // Khởi tạo Mảng 3D
    // Tính toán Bao Hàm Loại Trừ
    return 0;
}
```

---

## Bài 14: CỘNG CẤP SỐ CỘNG VÀO ĐOẠN (ARITHMETIC PROGRESSION UPDATE)

### Subtask 1 (50% số điểm): N <= 1000
Thuật toán ngây thơ cộng dồn bình thường.

- **Thuật toán:** Duyệt từ L đến R, tại mỗi bước i, cộng giá trị d = d + step.
- **Kiểm tra:** O(N*Q).
- **Đánh giá:** Chậm chạp khi số lượng đoạn quá nhiều.

### Subtask 2 (50% số điểm): N <= 10^6
Mảng hiệu bậc 2 (Difference of Difference Array).

- Sử dụng 2 lần mảng hiệu (Đạo hàm cấp 2).
- Cấp số cộng có gia số d không đổi, đạo hàm bậc 2 của nó là các điểm xung lực rời rạc.

**Tư duy thuật toán (O(N)):**
1. Thay vì cập nhật toàn bộ đoạn, ta cập nhật vào mảng hiệu bậc 2 D2.
2. Gia số đầu tiên tại L là: D2[L] += start_val.
3. Từ L+1 đến R, vì nó là cấp số cộng, độ chênh lệch là d, ta chỉ cần D2[L+1] += d.
4. Tại R+1, cấp số cộng kết thúc đột ngột, ta trừ đi: D2[R+1] -= (start_val + (R-L)*d + d).
5. Sau khi thực hiện Q truy vấn, ta chạy Prefix Sum lần 1 trên D2 để được Mảng hiệu bậc 1.
6. Chạy Prefix Sum lần 2 trên Mảng hiệu bậc 1 để khôi phục Mảng gốc A.

> **Lưu ý khởi tạo:** Cần tính toán cực kỳ cẩn thận chỉ số R+1 và R+2 để không bị lọt dữ liệu rác.

**Code mẫu:**
```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if (fopen("BAI14.INP", "r")) { freopen("BAI14.INP", "r", stdin); freopen("BAI14.OUT", "w", stdout); }
    // Cấu trúc Mảng hiệu bậc 2
    return 0;
}
```

---

## Bài 15: TỔNG TRÊN LƯỚI LỤC GIÁC (HEXAGONAL GRID)

### Subtask 1 (50% số điểm): N <= 100
Mô phỏng trục tọa độ X, Y.

- **Thuật toán:** Tính trực tiếp theo khoảng cách Manhattan.
- **Kiểm tra:** Vét cạn.
- **Đánh giá:** Thiếu tối ưu hóa.

### Subtask 2 (50% số điểm): N <= 1000
Dùng hệ tọa độ dời (Axial Coordinates) để biến lưới lục giác thành Mảng 2D.

- Chuyển lưới lục giác về ma trận 2D thông thường.
- Áp dụng Prefix Sum 2D lên lưới này.

**Tư duy thuật toán (O(N)):**
1. Hệ tọa độ hình bình hành giúp ánh xạ lục giác về mảng chữ nhật.
2. Khi đó, một truy vấn tổng khu vực lục giác có thể biểu diễn bằng tổng của 1 hoặc 2 hình chữ nhật ghép lại.
3. Sử dụng công thức của Bài 5 để xử lý phần còn lại trong O(1).

> **Lưu ý khởi tạo:** Việc Mapping tạo ra mảng 2D bị chéo, cần cẩn thận giới hạn cận.

**Code mẫu:**
```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    return 0;
}
```

---

## Bài 16: PREFIX SUM KẾT HỢP SEGMENT TREE (LƯỜI BIẾNG)

### Subtask 1 (50% số điểm): N <= 1000
Mảng tiền tố tĩnh chỉ đáp ứng bài toán tĩnh.

- **Thuật toán:** Cập nhật O(N), truy vấn O(1).
- **Kiểm tra:** O(Q*N).
- **Đánh giá:** Khi mảng bị cập nhật liên tục, Prefix Sum gốc bị vô hiệu.

### Subtask 2 (50% số điểm): N <= 2.10^5
Lazy Propagation trên Cây Phân Đoạn.

- Segment Tree bản chất là cấu trúc lưu tiền tố theo phân cấp nhị phân.
- Dùng Lazy để hoãn việc cập nhật xuống đáy cây.

**Tư duy thuật toán (O(N)):**
1. Mỗi node của cây lưu tổng của đoạn con.
2. Khi cộng V vào đoạn [L, R], ta tìm các node bao phủ đoạn đó và dán nhãn 'Lazy += V'.
3. Khi cần truy vấn tổng, ta mới đẩy nhãn Lazy xuống các node con.
4. Độ phức tạp O(log N) cho cả cập nhật và truy vấn.

> **Lưu ý khởi tạo:** Bộ nhớ cho Segment tree phải được cấp phát là 4*N.

**Code mẫu:**
```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    // Thuật toán Segment Tree Lazy
    return 0;
}
```

---

## Bài 17: TIỀN TỐ CỦA DÃY FIBONACCI

### Subtask 1 (50% số điểm): N <= 1000
Tính toán ma trận Fibonacci trực tiếp.

- **Thuật toán:** Dùng for.
- **Kiểm tra:** O(N).
- **Đánh giá:** Rất chậm nếu truy vấn đến phần tử thứ 10^18.

### Subtask 2 (50% số điểm): N <= 10^18
Nhân Ma Trận (Matrix Exponentiation) + Tính chất tiền tố Fibonacci.

- Công thức tuyệt diệu: Sum(F_1...F_N) = F_{N+2} - 1.
- Tính F_{N+2} trong O(log N) bằng nhân ma trận.

**Tư duy thuật toán (O(N)):**
1. Ta có ma trận cơ sở: [[1, 1], [1, 0]].
2. Lũy thừa ma trận lên N+1 lần để lấy F_{N+2}.
3. Trừ 1 ở kết quả. Mọi thứ tính trên modulo 10^9+7.

> **Lưu ý khởi tạo:** Phép nhân ma trận cần dùng mod để không tràn số.

**Code mẫu:**
```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    // Thuật toán Nhân ma trận Fibonacci
    return 0;
}
```

---

## Bài 18: TỔNG TRỌNG SỐ TRÊN ĐỒ THỊ DAG

### Subtask 1 (50% số điểm): N <= 100
Đồ thị có hướng không chu trình (DAG).

- **Thuật toán:** Duyệt DFS mọi nhánh.
- **Kiểm tra:** O(V + E) mỗi lần gọi.
- **Đánh giá:** Đồ thị DAG có thể có 2^N đường đi, gây đứng máy.

### Subtask 2 (50% số điểm): N <= 10^5
Quy hoạch động trên DAG (DP / Prefix Sum Graph).

- Sắp xếp Topo (Topological Sort).
- Tính tổng dồn từ đỉnh gốc theo thứ tự Topo.

**Tư duy thuật toán (O(N)):**
1. Đỉnh u chỉ được tính toán khi tất cả các đỉnh trỏ vào u đã tính xong.
2. Sử dụng hàng đợi (Queue) In-degree để duyệt chuẩn xác.
3. DP[v] = Sum(DP[u]) với mọi u -> v.

> **Lưu ý khởi tạo:** Lưu ý bài toán này ứng dụng Mảng tiền tố mở rộng trên Đồ thị.

**Code mẫu:**
```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    // Thuật toán DAG Topological Sort
    return 0;
}
```

---

## Bài 19: XỬ LÝ ẢNH MÀU KÊNH ALPHA (IMAGE INTEGRAL)

### Subtask 1 (50% số điểm): N <= 100
Quét ma trận lưới ảnh bình thường.

- **Thuật toán:** For.
- **Kiểm tra:** O(N*M).
- **Đánh giá:** Bộ lọc Gaussian mờ ảnh sẽ TLE.

### Subtask 2 (50% số điểm): N <= 2000
Bản chất là Tiền Tố 2D siêu tốc độ (Integral Image).

- Tương đương Bài 5 nhưng dữ liệu RGB rất lớn (4 kênh màu).
- Tính Prefix Sum 2D cho từng kênh R, G, B, A độc lập.

**Tư duy thuật toán (O(N)):**
1. Hệ thống thị giác máy tính Open CV dùng đúng cấu trúc này.
2. Tạo 4 mảng 2D cho 4 màu, áp dụng Inclusion-Exclusion.

> **Lưu ý khởi tạo:** Cần tối ưu I/O stream mạnh để đọc ghi nhanh.

**Code mẫu:**
```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    return 0;
}
```

---

## Bài 20: XÓA 1 PHẦN TỬ ĐỂ CÂN BẰNG TỔNG

### Subtask 1 (50% số điểm): N <= 1000
Cứ thử xóa từng phần tử một.

- **Thuật toán:** Duyệt i, xóa A[i]. Sau đó duyệt mảng tính tổng chẵn, tổng lẻ.
- **Kiểm tra:** O(N^2).
- **Đánh giá:** TLE khi N = 10^5.

### Subtask 2 (50% số điểm): N <= 10^5
Dùng 4 Mảng tiền tố: Chẵn/Lẻ Trái và Chẵn/Lẻ Phải.

- Khi xóa A[i], các phần tử bên trái không đổi chỉ số.
- Các phần tử bên phải bị dịch sang trái 1 bậc, nên chẵn biến thành lẻ, lẻ biến thành chẵn.

**Tư duy thuật toán (O(N)):**
1. Lập mảng PrefEven, PrefOdd tính từ trái sang phải.
2. Lập mảng SuffEven, SuffOdd tính từ phải sang trái.
3. Thử xóa i: Tổng chẵn mới = PrefEven[i-1] + SuffOdd[i+1].
4. Tổng lẻ mới = PrefOdd[i-1] + SuffEven[i+1].
5. Nếu bằng nhau thì đếm++.

> **Lưu ý khởi tạo:** Chú ý xử lý biên khi i=0 (không có phần tử bên trái) và i=N-1.

**Code mẫu:**
```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if (fopen("BAI20.INP", "r")) { freopen("BAI20.INP", "r", stdin); freopen("BAI20.OUT", "w", stdout); }
    int n;
    if (!(cin >> n)) return 0;
    vector<long long> a(n);
    long long totalEven = 0, totalOdd = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i % 2 == 0) totalEven += a[i];
        else totalOdd += a[i];
    }
    long long curEven = 0, curOdd = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        long long rightEven = totalEven - curEven - (i % 2 == 0 ? a[i] : 0);
        long long rightOdd = totalOdd - curOdd - (i % 2 != 0 ? a[i] : 0);
        if (curEven + rightOdd == curOdd + rightEven) ans++;
        if (i % 2 == 0) curEven += a[i];
        else curOdd += a[i];
    }
    cout << ans << "\n";
    return 0;
}
```

---

## Bài 21: ÔN TẬP TỔNG ĐOẠN (STATIC RANGE SUM - TỔNG HỢP)

### Subtask 1 (50% số điểm): N, Q <= 1000
Dạng bài tập cơ bản nhắc lại Bài 1.

- **Thuật toán:** Dùng For lặp qua O(N^2).
- **Kiểm tra:** Không tối ưu cho thời gian thực.
- **Đánh giá:** Chậm và gây TLE ở Test lớn.

### Subtask 2 (50% số điểm): N, Q <= 2.10^5
Áp dụng Mảng tiền tố 1 chiều chuẩn mực.

- Giống hệt cách tiếp cận của Bài 1, nhằm củng cố kiến thức gốc.
- Lấy S[R] - S[L-1].

**Tư duy thuật toán (O(N)):**
1. Lập mảng Pref.
2. Tại mỗi test case đọc L, R và xuất ra Pref[R] - Pref[L-1].

> **Lưu ý khởi tạo:** Cẩn thận nếu số lượng phần tử N lên 200,000 và giá trị 10^9 thì tổng sẽ vượt qua giới hạn của kiểu int 32-bit. Cần dùng kiểu dữ liệu long long (64-bit) trong C++.

**Code mẫu:**
```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if (fopen("BAI1.INP", "r")) { freopen("BAI1.INP", "r", stdin); freopen("BAI1.OUT", "w", stdout); }
    int n, q;
    if (!(cin >> n >> q)) return 0;
    vector<long long> pref(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        long long x; cin >> x;
        pref[i] = pref[i-1] + x;
    }
    while (q--) {
        int l, r; cin >> l >> r;
        cout << pref[r] - pref[l-1] << "\n";
    }
    return 0;
}
```

---

## Bài 22: ÔN TẬP ĐẾM ĐOẠN CON (SUBARRAY SUM - TỔNG HỢP)

### Subtask 1 (50% số điểm): N <= 5000
Dạng bài tập nhắc lại thuật toán Tìm đoạn con có tổng bằng K.

- **Thuật toán:** O(N^2) với Prefix Sum thô.
- **Kiểm tra:** Vét cạn S_i - S_j.
- **Đánh giá:** Rất nguy hiểm ở hệ thống có dữ liệu siêu lớn.

### Subtask 2 (50% số điểm): N <= 2.10^5
Lần nữa củng cố Mảng tiền tố kết hợp Bảng Băm (Hash Map).

- Bài toán rất hay gặp trong các kỳ thi Học Sinh Giỏi và Tuyển dụng.
- Hash Map lưu trữ số lần xuất hiện của các S_j.

**Tư duy thuật toán (O(N)):**
1. Cộng dồn sum += A[i].
2. Nếu sum - K có trong map, đáp án += map[sum - K].
3. Cập nhật map[sum]++.

> **Lưu ý khởi tạo:** Trong C++, dùng unordered_map thay cho map để đạt thời gian O(1) trung bình cho mỗi thao tác, giúp tổng thuật toán tiệm cận O(N).

**Code mẫu:**
```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if (fopen("BAI2.INP", "r")) { freopen("BAI2.INP", "r", stdin); freopen("BAI2.OUT", "w", stdout); }
    int n; long long k;
    if (!(cin >> n >> k)) return 0;
    long long cur = 0, ans = 0;
    map<long long, int> cnt;
    cnt[0] = 1;
    for (int i = 0; i < n; ++i) {
        long long x; cin >> x;
        cur += x;
        if (cnt.count(cur - k)) ans += cnt[cur - k];
        cnt[cur]++;
    }
    cout << ans << "\n";
    return 0;
}
```

---

## Bài 23: ÔN TẬP TỔNG MA TRẬN 2D

### Subtask 1 (50% số điểm): N, M <= 100
Bài toán tổng hình chữ nhật 2D.

- **Thuật toán:** Bao hàm - Loại trừ nhưng giới hạn nhỏ.
- **Kiểm tra:** O(1) mỗi truy vấn nếu đã lập bảng 2D.
- **Đánh giá:** Tiền đề để giải quyết ảnh y khoa và xử lý tín hiệu.

### Subtask 2 (50% số điểm): N, M <= 1000
Bài tập Tổng hợp giúp học sinh quen tay gõ công thức cắt mảng 2D.

- Luyện tính cẩn thận với 4 điểm cực của hình chữ nhật: S[r2][c2] - S[r1-1][c2] - S[r2][c1-1] + S[r1-1][c1-1].

**Tư duy thuật toán (O(N)):**
1. Tuyệt đối không nhầm lẫn giữa i, j và r1, c1.
2. Mọi thao tác trừ phải lùi đi 1 đơn vị (-1) vì tính phần bù của diện tích.

> **Lưu ý khởi tạo:** Luôn cấp phát bộ nhớ động bằng std::vector để mảng 1000x1000 không bị tràn Stack.

**Code mẫu:**
```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if (fopen("BAI3.INP", "r")) { freopen("BAI3.INP", "r", stdin); freopen("BAI3.OUT", "w", stdout); }
    int n, m, q;
    if (!(cin >> n >> m >> q)) return 0;
    vector<vector<long long>> pref(n + 1, vector<long long>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            long long x; cin >> x;
            pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + x;
        }
    }
    while (q--) {
        int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
        long long ans = pref[r2][c2] - pref[r1-1][c2] - pref[r2][c1-1] + pref[r1-1][c1-1];
        cout << ans << "\n";
    }
    return 0;
}
```

---

## Bài 24: ÔN TẬP MẢNG HIỆU 1D

### Subtask 1 (50% số điểm): N, Q <= 1000
Kiểm tra kỹ thuật Mảng Hiệu cơ bản.

- **Thuật toán:** Thay đổi 2 giá trị D[L] += V và D[R+1] -= V.
- **Kiểm tra:** Đơn giản O(N+Q).
- **Đánh giá:** Rất hiệu quả so với O(N*Q).

### Subtask 2 (50% số điểm): N, Q <= 10^6
Giới hạn rất lớn, lên tới 1 triệu phần tử.

- Với Q = 10^6, thời gian xử lý I/O là trở ngại lớn nhất.
- Cần sử dụng cin.tie(NULL) trong C++.

**Tư duy thuật toán (O(N)):**
1. Tại D[L] ta cộng V để bơm năng lượng vào.
2. Tại D[R+1] ta trừ V để rút năng lượng, tránh tràn ra ngoài.
3. Cuối cùng chạy Prefix sum: A[i] = A[i-1] + D[i].

> **Lưu ý khởi tạo:** Vì số lần đọc vào là 1,000,000 lần, ta không được dùng std::endl để xuống dòng, phải dùng \n.

**Code mẫu:**
```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if (fopen("BAI4.INP", "r")) { freopen("BAI4.INP", "r", stdin); freopen("BAI4.OUT", "w", stdout); }
    int n, q;
    if (!(cin >> n >> q)) return 0;
    vector<long long> diff(n + 2, 0);
    while (q--) {
        int l, r; long long v;
        cin >> l >> r >> v;
        diff[l] += v;
        diff[r + 1] -= v;
    }
    long long cur = 0;
    for (int i = 1; i <= n; ++i) {
        cur += diff[i];
        cout << cur << (i == n ? "" : " ");
    }
    cout << "\n";
    return 0;
}
```

---

## Bài 25: ÔN TẬP MẢNG HIỆU 2 CHIỀU

### Subtask 1 (50% số điểm): N, M <= 100
Bài toán khó nhất của bộ kỹ thuật tĩnh.

- **Thuật toán:** Cộng mảng hiệu 2 chiều ở 4 đỉnh.
- **Kiểm tra:** Tốc độ cực nhanh.
- **Đánh giá:** Tuyệt hảo.

### Subtask 2 (50% số điểm): N, M <= 1000, Q <= 100000
Phục hồi hình ảnh ma trận sau Q lần cập nhật vùng.

- D[r1][c1] += V
- D[r2+1][c1] -= V
- D[r1][c2+1] -= V
- D[r2+1][c2+1] += V

**Tư duy thuật toán (O(N)):**
1. Luyện thói quen ghi nhớ 4 tọa độ này, nó là kiến thức nền tảng để giải bài Stamping the Grid (Leetcode 2132).
2. Kết thúc bằng Prefix Sum 2D chuẩn.

> **Lưu ý khởi tạo:** Cần cẩn thận tràn chỉ số, mảng D phải cấp phát kích thước (N+2) x (M+2).

**Code mẫu:**
```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if (fopen("BAI5.INP", "r")) { freopen("BAI5.INP", "r", stdin); freopen("BAI5.OUT", "w", stdout); }
    int n, m, q;
    if (!(cin >> n >> m >> q)) return 0;
    vector<vector<long long>> d(n + 2, vector<long long>(m + 2, 0));
    while (q--) {
        int r1, c1, r2, c2; long long v;
        cin >> r1 >> c1 >> r2 >> c2 >> v;
        d[r1][c1] += v;
        d[r2+1][c1] -= v;
        d[r1][c2+1] -= v;
        d[r2+1][c2+1] += v;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            d[i][j] += d[i-1][j] + d[i][j-1] - d[i-1][j-1];
            cout << d[i][j] << (j == m ? "" : " ");
        }
        cout << "\n";
    }
    return 0;
}
```

---

