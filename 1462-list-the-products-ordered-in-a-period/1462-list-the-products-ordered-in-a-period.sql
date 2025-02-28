# Write your MySQL query statement below

select p.product_name as product_name,sum(o.unit) as unit from 
products as p
 join
orders as o
on
p.product_id = o.product_id
WHERE YEAR(o.order_date)='2020' AND MONTH(o.order_date)='02'

GROUP BY p.product_name
having sum(o.unit)>=100;

