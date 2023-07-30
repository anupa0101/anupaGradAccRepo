CREATE DATABASE anupa_database;

USE anupa_database;
CREATE TABLE schools(
	id INT NOT NULL AUTO_INCREMENT,
    name VARCHAR(255) NOT NULL,
    PRIMARY KEY (id)
    );
ALTER TABLE schools 
	ADD location VARCHAR(255);

    
CREATE TABLE student_table(
	id INT NOT NULL AUTO_INCREMENT,
	name VARCHAR(255) NOT NULL,
    age INT,
    PRIMARY KEY(id),
    school VARCHAR(255) NOT NULL,
    FOREIGN KEY(school) REFERENCES schools(id)
);
ALTER TABLE student_table 
	ADD grade INT;

INSERT INTO schools(name, location)
	VALUES('Royal college', 'Reid avenue'),
    ('Visaka vidyalaya','Police park'),
    ('Peters college', 'Kollupitiya');

INSERT INTO student_table(name,age,school,grade)
	VALUES('Anupa Satharasinghe',25,'Royal college',13),
    ('Senuri Satharasinghe', 27, 'Visaka vidyalaya',15),
     ('Vishal arangala', 77, 'Peters college',15),
     ('Venuka Herath', 45, 'Royal college',15);

    