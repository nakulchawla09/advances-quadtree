# Spatial Indexing

## PR Quad Tree and MX-CIF Quad Tree
===============================

You can find usage details of interfaces available for Spatial Data Indexing in this document.
There are two indexes constructed that extend SpatialIndexInterface. - 

* PointSpatialIndex
	* Uses Point Region Quadtree to index data from the Point table
* RectangleSpatialIndex 
	* Uses MX-CIF Quadtree to index data from the Rectangle table.

PointSpatialIndex contains the following functions:
	
	PointCollection search(Rectangle bounds)
	Search the query rectangle provided and return all points satisfying the query
		bounds - Diagonal Coordinates of the query rectangle. Assumes that the getCoordinates function returns
		         (x1,y1) and (x2,y2) in order
		Returns PointCollection - Collection of points satisfying the query
	
	RectangleCollection searchRectangle(Rectangle)
	This method is not implemented for the class. Throwa an exception containing String message if invoked.
	
	void createIndex(PointCollection points,float width, float height)
	Creates Point Spatial Data Index for the given set of points
		points - Collection of points to be indexed
		width, height - of the bounding box containing all the points. Assumes that the origin (0,0) is the centre
						of the bounding box with quadrant dimension width/2 * height/2
		Returns void
	
	void createIndex(RectangleCollection, float, float)
	This method is not implemented for the class. Throwa an exception containing String message if invoked.
		
	bool update(PointCollection points,float width, float height)
	Updates the Point Spatial Data index created. This method deletes existing index structure and constructs it for given set of points
		points - Collection of points to be indexed
		width, height - of the bounding box containing all the points. Assumes that the origin (0,0) is the centre
						of the bounding box with quadrant dimension width/2 * height/2
		Returns bool - sucess status of the update operation
	
	bool update(RectangleCollection,float, float)
	This method is not implemented for the class. Throwa an exception containing String message if invoked.
	
	bool deleteIndex()
	Deletes index structure for Point Spatial data
		Returns bool - success status of the delete operation
	
RectangleSpatialIndex contains the following functions:
	
	PointCollection search(Rectangle)
	This method is not implemented for the class. Throwa an exception containing String message if invoked.
	
	RectangleCollection searchRectangle(Rectangle bounds)
	Search the query rectangle provided and return all rectangles satisfying the query
		bounds - Diagonal Coordinates of the query rectangle. Assumes that the getCoordinates function returns
		         (x1,y1) and (x2,y2) in order
		Returns RectangleCollection - Collection of rectangles satisfying the query
		
	void createIndex(PointCollection, float, float)
	This method is not implemented for the class. Throwa an exception containing String message if invoked.
	
	void createIndex(RectangleCollection rectangles, float width, float height)
	Creates Rectangle Spatial Data Index for the given set of rectangles
		rectangles - Collection of rectangles to be indexed
		width, height - of the bounding box containing all the rectangles. Assumes that the origin (0,0) is the centre
						of the bounding box with quadrant dimension width/2 * height/2
		Returns void
		
	bool update(PointCollection,float, float)
	This method is not implemented for the class. Throwa an exception containing String message if invoked.
	
	bool update(RectangleCollection rectangles,float width, float height)
	Updates the Rectangle Spatial Data index created. This method deletes existing index structure and constructs it for given set of rectangles
		rectangles - Collection of rectangles to be indexed
		width, height - of the bounding box containing all the rectangles. Assumes that the origin (0,0) is the centre
						of the bounding box with quadrant dimension width/2 * height/2
		Returns bool - sucess status of the update operation
		
	bool deleteIndex()
	Deletes index structure for Rectangle Spatial data
		Returns bool - success status of the delete operation

Images for reference:

Figure 1: Bounding Box Structure 
![Bounding Box Structure](https://github.com/nakulchawla09/advances-quadtree/blob/master/new/advdbSpatialTest/Test/Images/BoundingBoxStructure.png)

Figure 2: Structure of Quadtree Node
![Structure of Quadtree Node](https://github.com/nakulchawla09/advances-quadtree/blob/master/new/advdbSpatialTest/Test/Images/StructureOfQuadtreeNode.png)

Figure 3: Points Visualization in Quadtree
![Points Visualization in Quadtree](https://github.com/nakulchawla09/advances-quadtree/blob/master/new/advdbSpatialTest/Test/Images/TestCase1PointsVisualization.png)

Figure 4: Rectangles Visualization in Quadtree
![Rectangles Visualization in Quadtree](https://github.com/nakulchawla09/advances-quadtree/blob/master/new/advdbSpatialTest/Test/Images/TestCaseRectangulesVisualization.png)

========================================================================================================================

