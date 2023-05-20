select person_name from 
(select person_name, @total_weight := @total_weight + weight as total_weight from Queue,
(select @total_weight := 0) as tmp order by turn) as t
where total_weight <= 1000 order by total_weight desc limit 1
