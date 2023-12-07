/**
* Interface to Game of Life Grid.
* The CellGridCanvas can deal with any grid, not only the Game of Life.
* Copyright 1996-2004 Edwin Martin <edwin@bitstorm.nl>
* @author Edwin Martin
*/

package alpha.game.cell.gameoflife;

import java.awt.Dimension;
import java.util.Enumeration;

public interface CellGrid {
	/**
	 * Clears grid.
	 */
	public void clear();

	/**
	 * Get status of cell (alive or dead).
	 * 
	 * @param col
	 *            x-position
	 * @param row
	 *            y-position
	 * @return living or not
	 */
	public boolean getCell(int col, int row);

	/**
	 * Get dimension of cellgrid.
	 * 
	 * @return dimension
	 */
	public Dimension getDimension();

	/**
	 * Get cell-enumerator. Enumerates over all living cells (type Cell).
	 * 
	 * @return Enumerator over Cell.
	 * @see Cell
	 */
	public Enumeration<Cell> getEnum();

	/**
	 * Resize the cell grid.
	 * 
	 * @param col
	 *            new number of columns.
	 * @param row
	 *            new number of rows.
	 */
	public void resize(int col, int row);

	/**
	 * Set status of cell (alive or dead).
	 * 
	 * @param col
	 *            x-position
	 * @param row
	 *            y-position
	 * @param cell
	 *            living or not
	 */
	public void setCell(int col, int row, boolean cell);
}