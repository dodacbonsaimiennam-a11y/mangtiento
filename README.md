# GIỚI THIỆU CHUNG: HỆ THỐNG BÀI TẬP CHUYÊN ĐỀ MẢNG TIỀN TỐ (PREFIX SUM & DIFFERENCE ARRAY)

## 1. Tổng Quan Về Chuyên Đề
Chào mừng bạn đến với bộ tài liệu bồi dưỡng thuật toán chuyên sâu về **Mảng Tiền Tố (Prefix Sum)** và **Mảng Hiệu (Difference Array)**. Đây là hai cấu trúc dữ liệu cốt lõi và quan trọng bậc nhất trong Lập trình thi đấu (Competitive Programming) cũng như Tối ưu hóa hiệu suất phần mềm (Software Optimization). 

Chuyên đề này được thiết kế dựa trên phương pháp sư phạm tịnh tiến, giúp người học đi từ những khái niệm nền tảng toán học cơ bản nhất cho đến các kỹ thuật xử lý truy vấn động lực học siêu cấp nhiều chiều, có khả năng giảm độ phức tạp thời gian từ $O(N \times Q)$ xuống $O(N)$ hoặc thậm chí $O(1)$.

Toàn bộ hệ thống bài giảng, phương pháp giải, và bộ test đầu cuối (Input/Output) đều được tổng hợp, rà soát chéo và chiết xuất từ hệ thống AI DeepResearch kết hợp với dữ liệu thi đấu thực tế từ các nền tảng lớn (CSES, LeetCode, Codeforces, VNOI).

## 2. Cấu Trúc Hệ Thống Lưu Trữ
Hệ thống tài liệu bao gồm **25 bài tập** được chia làm 2 phần chính:

### Phần 1: Bồi Dưỡng Kiến Thức (20 Bài Tập)
Được thiết kế để rèn luyện tư duy từ số 0 đến cấp độ thi đấu Quốc gia, phân bổ thành 4 mức độ:
*   **Mức độ 1 - Cơ Bản (5 bài):** Nhận biết và thông hiểu cách xây dựng mảng cộng dồn 1D cơ bản, mảng hiệu tĩnh và các phép tính logic (XOR).
*   **Mức độ 2 - Trung Bình (5 bài):** Vận dụng cấu trúc phức hợp, kết hợp Hash Map (Bảng băm), xử lý chia hết (Modulo) và nâng cấp lên không gian 2 chiều (Prefix 2D).
*   **Mức độ 3 - Khá Khó (5 bài):** Kỹ thuật nâng cao, kết hợp cấu trúc dữ liệu rời rạc (BIT, Deque, Sliding Window) và đạo hàm mảng hiệu bậc 2.
*   **Mức độ 4 - Rất Khó (5 bài):** Mức độ thi tuyển IOI/HSG Quốc gia. Tái cân bằng mảng, phân ly giao tuyến, và xử lý mảng hiệu đa chiều Offline trên hệ trục toạ độ chéo (Manhattan).

### Phần 2: Kiểm Tra Đánh Giá Tổng Hợp (5 Bài Tập)
*Nằm trong thư mục `Tong_Hop`*
Bộ 5 bài tập này là bài kiểm tra năng lực cuối khóa (Mock Test). Các bài trải dài đủ 5 mức độ (từ dễ đến cực khó), mang tính chất tổng hợp các kỹ thuật đã học để đánh giá thực lực tối đa của học viên.

## 3. Hệ Thống Mã Nguồn Giải Thuật Tối Ưu (Solutions)
Toàn bộ 25 bài tập đều có mã nguồn lời giải bằng hai ngôn ngữ **C++** và **Python**, được viết với cấu trúc IO File thi đấu (tự động đọc ghi file qua `freopen`).
*   Các giải thuật được tối ưu hóa đến mức cực hạn (O(N) hoặc O(N log N)), sử dụng những tư duy hiện đại nhất.
*   Bạn có thể đọc tư duy thuật toán chi tiết, giải thích các Subtask và code mẫu từng bài trong bộ Báo cáo **`Loi_Giai_Chi_Tiet_25Bai.docx`** (hoặc bản markdown `.md`).

## 4. Hệ Thống Test Đầu Cuối (End-to-End Test IN/OUT) Khổng Lồ
Một điểm nhấn tạo nên giá trị học thuật vô giá của bộ tài liệu này là **Hệ thống Test Cases độc lập** được đính kèm cho toàn bộ 25 bài tập. Đây không phải là các test được sinh ngẫu nhiên hời hợt, mà là một hệ thống được lập trình rà soát vô cùng kỹ lưỡng:

*   **Quy mô đồ sộ:** Từng bài tập đều có 10 Test cases hoàn chỉnh (định dạng `*.INP` và `*.OUT`), tổng cộng **500 files Input/Output** khổng lồ chứa hàng triệu dòng dữ liệu.
*   **Phủ kín mọi giới hạn dữ liệu (Subtasks):** Hệ thống test được phân tách theo đúng cấu trúc. 
    - Test 1 - 5: Các Subtask nhỏ và Corner Cases tinh vi.
    - Test 6 - 10: Các bộ test nén dữ liệu khổng lồ $N, Q \le 2 \cdot 10^5$ (Thậm chí 1 triệu truy vấn) để ép các thuật toán có độ phức tạp $O(N^2)$ phải báo lỗi Time Limit Exceeded (TLE).
*   **Tính chính xác tuyệt đối:** Tất cả Output đều được sinh ra và đối soát (cross-check) tự động bằng trình Validation độc lập để khớp hoàn hảo 100% với giới hạn biên của đề bài.

## 5. Hướng Dẫn Sử Dụng
*   **Với Giáo Viên/Huấn Luyện Viên:** 
    - Sử dụng các file đề bài chuẩn **`De_Bai.md`** hoặc **`De_Bai_V6.docx`** để phát cho học sinh làm tài liệu.
    - Cung cấp **`Loi_Giai_Chi_Tiet_25Bai.docx`** làm cẩm nang học thuật, bài giải chi tiết lý thuyết thuật toán.
    - Sử dụng các file Test IN/OUT trong từng thư mục `test/` để import thẳng lên các hệ thống tự động chấm điểm (Themis, CMS, DomJudge, HackerRank...).
*   **Với Học Sinh:** Khuyến nghị làm bài theo đúng trình tự từ Bài 1 đến Bài 20 để cảm nhận sự nâng cấp trong tư duy. Không nên chuyển sang bài mới khi chưa hiểu rõ "Phân tích giải thuật" của bài trước đó. Cần hoàn thành trọn vẹn bộ 20 bài trước khi thử sức với 5 bài trong thư mục `Tong_Hop`.

---
*Tài liệu được tinh chỉnh và biên soạn cẩn thận nhằm mang lại trải nghiệm học thuật chuyên nghiệp nhất!*
