
# Add column to handle peak user count
ALTER TABLE recordstats
	ADD COLUMN all_time_peak INT NOT NULL AFTER cs_lost;

