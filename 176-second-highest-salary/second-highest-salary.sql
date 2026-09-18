select max(e1.salary) as SecondHighestSalary
from employee e1
inner join employee e2
on e1.salary < e2.salary;