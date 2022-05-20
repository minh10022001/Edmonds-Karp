# TTCS
Báo cáo:Thuật toán Edmonds-Karp

Môn : Thực tập cơ sở

Thực hiện: Nguyễn Văn Minh - B19DCCN439

*Thuật toán Edmonds-Karp sử dụng để tìm luồng cực đại trong mạng

*Hướng dẫn đưa dữ liệu vào để chạy chương trình thuật toán
- Từ đồ thị ta xây dựng từ thực tế, ta cần xác định số đỉnh, số cạnh (cung), đỉnh bắt đầu, đỉnh mục tiêu, chuyển đồ thị dành danh sách cạnh: với đỉnh đầu, đỉnh cuối, khả năng thông qua của cung
- Sau đó nhập Input vào chương trình, chương trình sẽ trả ra kết quả Output là giá trị luồng cực đại trong mạng đó
- *Ví dụ: Áp dụng thuật toán Edmonds-Karp tìm luồng cực đại trong mạng sau ( điểm bắt đầu 0, điểm mục tiêu 6)
- + ![image](https://user-images.githubusercontent.com/83805481/169513067-0a3271ea-4497-43c3-baf6-86625945c380.png)
- + Số đỉnh 7, số cạnh 11, đỉnh bắt đâu: 0, đỉnh mục tiêu: 6
- + Danh sách cạnh: 
      - 0 1 3
      - 0 3 3
      - 1 2 4
      - 2 0 3
      - 2 3 1
      - 2 4 2
      - 3 4 2
      - 3 5 6
      - 4 1 1
      - 4 6 1
      - 5 6 9

- + Chạy chương trình thuật toán
- + Nhập input:
- + ![image](https://user-images.githubusercontent.com/83805481/169515270-250bf566-c4a0-4e90-9a5a-aec4f8ba5a76.png)
-+ Output: 
- + ![image](https://user-images.githubusercontent.com/83805481/169515455-ff49bdd5-66a2-4103-b041-e5e95207d1ed.png)
- + Vậy luồng cực đại trong ví dụ này là 5

