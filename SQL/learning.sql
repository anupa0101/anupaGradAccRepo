/*structured query languge used to create read and update data from  
database. any rdbms uses sql. 
mysql is a rdbms based on sql
conevention: write the commands in capital and others like column and table names in simple
to write strings use single quotes 'mystring'

show databases;-- shows all the databases
CREATE DATABASE test;-- create databse called test. refresh to see it in schema
DROP DATABASE test; --delete database. deletes all data in the database



*/

CREATE DATABASE record_company; -- create a database for record company list
USE record_company; -- declares to use this database for the SQL queries
CREATE TABLE test(
	test_column INT,
    test_column2 INT
);-- create table with table name, then add the column names followed by the datatypes seperated by a comma

ALTER TABLE test
ADD test_column3 VARCHAR(255); 
/*-- use alter to change the table later after creating it. add a new column with variable length character array of 255 size- string*/

DROP TABLE test;-- delete table called test

/*
					LETS CREATE TABLES
*/
/* -Not null means it cannot have empty values. shoudl always have a 
    valid value. if we try to insert a band without an name, itwil throw an error
     
    ID column is the unique idenitifier. Here its an integer type and it cannot be null
    and we auto generate and auto increment it
    THE PRIMARY KEY IS THE ID COLUMN- added to the index
    quering with the primary key is much faster*/
CREATE TABLE bands(
	id INT NOT NULL AUTO_INCREMENT,
	name VARCHAR(255) NOT NULL,
    PRIMARY KEY(id)
);

/* table created is for albums it has the release year which can be null, name which cant be null
and id for indexing- primary key that cant be null and auo generated adnd incremented

to link to the bands table we create a band_id variable that is not null. It is the foreign key
that links albums table to bands table
TO DECLARE THIS use FOREIGN KEY(column inside this table) REFFERENCES other-table(column in that table to reffer to)
NOTE: if we add an album with a band_id not present in the bands table- error
--if we delete a band while having an entry in the albums table - throw an error
*/
CREATE TABLE albums(
	id INT NOT NULL AUTO_INCREMENT,
    name VARCHAR(255) NOT NULL,
	
    band_id INT NOT NULL,
    PRIMARY KEY(id),
    FOREIGN KEY (band_id) REFERENCES bands(id)
);
ALTER TABLE albums
ADD release_year INT; 

/*
					LETS ADD SOME BANDS
*/
/*
				id is auto generated so no need to add it manually, for bands only one other column - name
 syntax: INSER INTO tableName(list of columns you plan to add seperated by commas)
			VALUES(entry 1: contains entires for the columns defined aboe in order),(entry 2),.......;
*/
INSERT INTO bands(name)
	VALUES('Iron maiden'),
			('Anchor'),
			('Avengard');

INSERT INTO albums(name,release_year,band_id)
	VALUES('Siriyame',1997,1),
			('Ananthaya',NULL,2),
            ('Paradige',2022,3);
INSERT INTO albums(name,release_year,band_id)
	VALUES('orangotsng',2011,1);
INSERT INTO bands(name)
	VALUES('dunkolatataal');
  /*
					LETS update entries albums table
syntax: UPDATE tableName   
	SET column_name= value to add
	WHERE columnname= value  of the column where the change should be made;
*/     
UPDATE albums
	SET release_year=1990
	WHERE id=1;-- if of where the change should be made. if not added all release years become 1990
 /*
					LETS query from bands table
*/ 
SELECT  * FROM bands;  /*  asteric* will select all columns, from table name. Displays all columns of the table */ 
SELECT  name FROM bands;    /* will show only the name column of the table bands*/
SELECT * FROM bands LIMIT 2;/* will show only the top 2 entries of the table LIMIT*/
/* give aliases to column names*/
SELECT * FROM bands ORDER BY name;  /* will show all columns ordered in alphabeticl order using name column*/
SELECT * FROM bands ORDER BY name DESC;  /* will show all columns ordered in REVERSE alphabeticl order using name column*/
SELECT DISTINCT name from bands; /*  there could be bands with similar names- distinct helps to get distinct names only */
SELECT  * FROM albums
	WHERE release_year>1990 OR (band_id<5 AND band_id>0) ; /* will show only the entires filered*/
SELECT  name FROM albums
	WHERE release_year BETWEEN 2000 AND 2022; /* will show only the entires filered*/
SELECT  name FROM albums
	WHERE release_year IS NULL; /* will show only the entires filered*/
SELECT id AS 'Id of bands' , name AS 'Band names' FROM bands; /* give aliases to column names- these names
will be displayed. usefull later*/

 /*
					LETS delete entires from albums table
                    without where will delete all in the table
*/ 

DELETE FROM albums
	WHERE id=1;/* will  delete the filered rows*/
DELETE FROM albums	
	WHERE release_date=1997;/* will  delete the filered rows*/
SELECT * FROM albums;


 /*
					JOIN TABLES-IMPORTANT
	First select the table which should come first.
    then choose the 2nd table and the coumns ON which to compare for joining.
    synatax:  SELECT * FROM firstTable(left)
				JOIN secondTable(right) ON firstTable.cloumn_name=secondTable.column_name;
	normal join- will give the joined entries only with equal values
    left join- will give all the values of the left table and the joined ones with equal values. some may be empty
	right  join- will give all the values of the right table and the joined ones with equal values. some may be empty. not here because they are foreign key and must have an entry in bands

*/ 
SELECT * FROM bands
JOIN albums ON bands.id= albums.band_id;

SELECT * FROM bands
LEFT JOIN albums ON bands.id= albums.band_id;

SELECT * FROM bands
RIGHT JOIN albums ON bands.id= albums.band_id;

SELECT * FROM albums
RIGHT JOIN bands ON bands.id= albums.band_id; /*to demonstrate the right join*/

SELECT bands.name, bands.id FROM albums
RIGHT JOIN bands ON bands.id= albums.band_id; /*need to use bands.id*/
/* AGGREGATE FUNCTIONS*/

SELECT AVG(release_year) FROM albums; /* avg of release year in the albums table*/
SELECT SUM(release_year) FROM albums; /* SUM of release year in the albums table*/
SELECT COUNT(release_year) FROM albums; /* count of release year in the albums table*/

/* AGGREGATE FUNCTIONS with group by*/
SELECT band_id, COUNT(band_id) FROM albums/* gives the band_ids and the entry count for each band_id*/
GROUP BY band_id;/* group using band id*/

SELECT bands.name, COUNT(albums.id) FROM bands/*show the band name and the count of albums */
LEFT JOIN albums ON bands.id=albums.band_id
GROUP BY bands.id;/* group by band id, but band id isnt dissp;ayed as itsnot selected*/

/* using aliases*/
SELECT b.name AS band_name, COUNT(a.id) AS num_albums FROM bands AS b/*show the band name and the count of albums */
LEFT JOIN albums AS a ON b.id=a.band_id
GROUP BY b.id;/* group by band id*/

/*filter- cant use WHERE as it occurs before grouping. Use HAVING instead*/
SELECT bands.name, COUNT(albums.id) FROM bands/*show the band name and the count of albums */
LEFT JOIN albums ON bands.id=albums.band_id
GROUP BY bands.id
HAVING COUNT(albums.id)>0;/*use having to fileter not where */

/*filter- USING BOTH WHERE(occurs before group by) AND HAVING(occurs after group by)-*/

SELECT bands.name, COUNT(albums.id) FROM bands/*show the band name and the count of albums */
LEFT JOIN albums ON bands.id=albums.band_id
WHERE bands.name='Iron maiden'/*use where beffore group by */
GROUP BY bands.id
HAVING COUNT(albums.id)>0;/*use having after group by */