# Write your MySQL query statement below
-- select customer_id, cont_no_trans from Visits v inner join
-- (select visit_id, count(*) as cont_no_trans from Transactions group by visit_id) as tmp
-- on v.visit_id = tmp.visit_id;

SELECT v.customer_id, COUNT(*) as count_no_trans 
from Visits v where visit_id NOT IN (select distinct visit_id from Transactions) 
GROUP by v.customer_id;
