#include "Hash_table.h"

void Hash_table :: clear(){

	for(int i=0; i<hash_size; i++){

		Record tmp;

		table[i]=tmp;

	}

}



//哈希函数的设计
int hash(const Record &new_entry)
{

	return new_entry.the_key()%hash_size;

}



int hash(const Key &new_entry)
{

	return new_entry.the_key()%hash_size;

}




Error_code Hash_table :: insert(const Record &new_entry)

/* Post: If the Hash table is full, a code of overflow is returned. If the table already

contains an item with the key ofnew entry a code of duplicate error is returned.

Otherwise: The Record new entry is inserted into the Hash table

and success is returned.

Uses: Methods for classes Key , and Record . The function hash . */

{

	Error_code result = success;

	int probe_count, // Counter to be sure that table is not full.

	increment, // Increment used for quadratic probing.

	probe; // Position currently probed in the hash table.

	probe = hash(new_entry);

	probe_count = 0;

	increment = 1;

	if(retrieve((Record)new_entry,(Record&)new_entry)==success)
	    return duplicate_error;



	while (table[probe] != 0 // Is the location empty?

		&& table[probe] != -1 // empty because delete

		&& table[probe] != new_entry // Duplicate key?

		&& probe_count < (hash_size + 1)/2)
		{ // Has overflow occurred?

		probe_count++;

		probe = (probe + increment)%hash_size;

		increment += 2; // Prepare increment for next iteration.

	    }

	if (table[probe] == 0) table[probe] = new_entry;

	if (table[probe] == -1) table[probe] = new_entry;

	// Insert new entry.

	else if (table[probe] == new_entry) result = duplicate_error;

	else result = overflow; // The table is full.

	return result;

}



Error_code Hash_table :: retrieve(const Key &target, Record &found) const{

	int probe_count, // Counter to be sure that table is not full.

	increment, // Increment used for quadratic probing.

	probe; // Position currently probed in the hash table.

	probe = hash(target);

	probe_count = 0;

	increment = 1;

	while (table[probe] != 0 // Is the location empty?

		&& table[probe].the_key() != target.the_key() // not found

		&& probe_count < (hash_size + 1)/2) { // Has overflow occurred?

		probe_count++;

		probe = (probe + increment)%hash_size;

		increment += 2; // Prepare increment for next iteration.

	}

    if (table[probe].the_key() == target.the_key()){

		found = table[probe];

		return success;

	}

	else return not_present;

}



Error_code Hash_table :: remove(const Key &target, Record &found){

	int probe_count, // Counter to be sure that table is not full.

	increment, // Increment used for quadratic probing.

	probe; // Position currently probed in the hash table.

	probe = hash(target);

	probe_count = 0;

	increment = 1;

	while (table[probe] != 0 // Is the location empty?

		&& table[probe].the_key() != target.the_key() // not found

		&& probe_count < (hash_size + 1)/2) { // Has overflow occurred?

		probe_count++;

		probe = (probe + increment)%hash_size;

		increment += 2; // Prepare increment for next iteration.

	}

    if (table[probe].the_key() == target.the_key()){

		found=table[probe];

		table[probe]=-1;  //attention

		return success;

	}

	else return not_present;

}


