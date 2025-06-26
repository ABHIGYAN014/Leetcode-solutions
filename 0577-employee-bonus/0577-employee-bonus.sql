# Write your MySQL query statement below
select e1.name,b1.bonus 
from employee e1
left join bonus b1 on
e1.empId=b1.empId
where b1.bonus<1000 OR b1.bonus IS NULL