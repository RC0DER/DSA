# Write your MySQL query statement below
select d.name as Department, e1.name as Employee, e1.salary as Salary from Employee as e1
join Department as d
on e1.departmentid = d.id
left join Employee as e2
on e1.departmentid = e2.departmentid and e2.salary > e1.salary
group by e1.id, d.name, e1.name, e1.salary
having count(distinct e2.salary) < 1;