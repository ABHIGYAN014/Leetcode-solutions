# Write your MySQL query statement below
select s1.year,s1.price,p1.product_name from 
sales s1 join 
product p1 on
s1.product_id=p1.product_id