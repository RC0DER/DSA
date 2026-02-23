# Write your MySQL query statement below
SELECT Employee.name as Employee
FROM Employee as employee
JOIN Employee as manager
ON employee.managerID = manager.id
WHERE employee.salary > manager.salary;