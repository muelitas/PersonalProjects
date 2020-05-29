/**************************************************************
  * File:     splitRow.js
  * Author1:  Mario Esparza
  * Author2:  Diego Toquinto
  * Date:     05/27/2020
  * 
  * Given a table with information entered from a form, we are
  * using the script option to split single columns into three.
  * All new entries appear in the "New Registrations" view. We
  * grab these records and iterate through them. As we iterate
  * through them, we keep the original record, we create two
  * new records and we remove the attribute "new" from them.
  *
***************************************************************/
let table = base.getTable("People");
let view = table.getView("New Registrations");
let query = await view.selectRecordsAsync();

for (let record of query.records) {
	//Create row for parent1 and append information
	let newRecord1 = await table.createRecordAsync({
		"First Name": record.getCellValueAsString("Parent 1 First Name"),
		"Middle Name": record.getCellValueAsString("Parent 1 Middle Name"),
		"Last Name": record.getCellValueAsString("Parent 1 Last Name"),
		"Type": [{name: "Parent"}],
		"Newly Registered": false,
	});
	//Create row for parent2 and append information
	let newRecord2 = await table.createRecordAsync({
		"First Name": record.getCellValueAsString("Parent 2 First Name"),
		"Middle Name": record.getCellValueAsString("Parent 2 Middle Name"),
		"Last Name": record.getCellValueAsString("Parent 2 Last Name"),
		"Type": [{name: "Parent"}],
		"Newly Registered": false,
	});
	//Remove "New Registered" Tag
	await table.updateRecordAsync(record.id, {
		"Newly Registered": false,
	})
}
