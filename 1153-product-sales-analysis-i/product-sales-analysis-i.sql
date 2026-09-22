select product_name, year, price 
from Sales as s
join product as p
on s.product_id = p.product_id;