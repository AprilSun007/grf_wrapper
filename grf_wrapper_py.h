#ifndef GRF_WRAPPER_PY_H
#define GRF_WRAPPER_PY_H
#include<vector>
#include "grf_wrapper.h"

extern std::vector<Grf_wrapper> grf_wrapper_cache;

int grf_train(double **data, int num_rows, int num_cols, int weight_index,
				int outcome_index, int treatment_index, int instrument_index, char* option,
				int forest_num_tree,	//how many trees to grow in traing period
				int forest_ci_group_size,
				double forest_sample_fraction,	//sample used to grow each tree
				int tree_mtry, //number of variables considered during each split
				int tree_min_node_size,	//minimum size(# samples) a leave node is allowed to have. If honest tree, min_node_size applies to the size of the leaf by the second half of the sample
				bool tree_honesty,	//honest tree indicator
				double tree_honesty_fraction,	//fraction of the sample that will be used for split, usually between 0.5 - 0.8
				bool tree_prune_empty_leaves, //honest split may leads to empty leaves when using the second half of the sample for estimation, such leaves will be pruned if true
				double tree_alpha,	//maximum imbalance of the split. Each child is not allowed to be less than size(parent) * alpha
				double tree_imbalance_penalty,	// imbalance.penalty * (1.0 / size(left.child) + 1.0 / size(right.child)) applies to goodness of fit
				int sample_per_cluster,	 //when determine the examples used for performing splitting and populating the leaves, samples_per_cluster examples are drawn from the selected clusters. By default, equal to the size of the smallest cluster.
				int seed,
				int num_thread, 
				bool train_ind
	);

void grf_predict(int forest_index, 
				double **data, 
				double* predictions, 
				int num_rows, 
				int num_cols, 
				int weight_index,
				int outcome_index, 
				int treatment_index,
				int instrument_index, 
				char* option);

#endif