# Write your MySQL query statement below
select t2.id from  
weather t1 
cross join weather t2
where DATEDIFF(t2.recordDate,t1.recordDate)=1 
AND t2.temperature>t1.temperature