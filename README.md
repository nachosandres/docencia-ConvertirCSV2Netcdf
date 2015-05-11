# docencia-ConvertirCSV2Netcdf

### Commit log
Description of commits, from most recent to oldest.

#### Added valid ranges and device number
Set valid ranges/minimum for several variables. Device number added as global attribute.

#### Added time units
Time now has units attribute "hours since -first measurement-". Command for ending definition moved had to be moved for this.

#### Added and filled time coordinate
Filled time coordinate with hours since first measurement.

#### Added global attributes
Data related to the experiment as a whole (average value, etc.) added as global attributes.

#### Added units, title, ancillary radon-error
Added unit attributes to variable, title to the whole file, and ancillary variable relationship between radon concentration measurements and their relative uncertainty.

#### Added variable long names
Variables now have long names attributes for description, as well as standard names when this is possible.

#### Variable data introduced
Data values are now read from text file and assigned to netcdf variables, they are shown in .nc file.

#### Data sizes properly read nows
Fixed issue with reading data length. Now size is properly assigned to all variables.

#### Created first nc, no data, length still not properly defined
Test of .nc file generaion, without introducing data. Number of data rows is not yet correctly obtained from text file.

#### Definicion de variables
Added definition of C and NetCDF variables (ID, dimensions).

#### Downloaded text file, created executable
First commit after fork, tested compilation with netcdf flag.
