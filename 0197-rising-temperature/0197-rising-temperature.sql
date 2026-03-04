# Write your MySQL query statement below


select combined.id from (select w.id, w.recordDate, w.temperature, w2.temperature as tmp from Weather w left join Weather w2 on DATEDIFF(w.recordDate, w2.recordDate) = 1) combined where combined.temperature > combined.tmp;