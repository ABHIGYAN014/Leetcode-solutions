# Write your MySQL query statement below
with cte as(
select*,
dense_rank() over(partition by Department order by salary desc) as rnk
from(
select d.name as Department,e.name as Employee,e.salary as Salary
from Employee e
left join department d
on e.departmentId=d.id
) as temp)
select Department,Employee,Salary from cte where 
rnk<4
