from Bio.PDB import *
import sys

p=PDBParser()
s=p.get_structure('X', sys.argv[1])
atom_list=Selection.unfold_entities(s,'A')
ns=NeighborSearch(atom_list)
center=atom_list[0].get_coord()
R=8.0
neighbor_l=ns.search(center,R)
residue_list=Selection.unfold_entities(neighbor_l,'R')

print residue_list