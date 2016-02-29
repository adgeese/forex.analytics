#pragma once
#include "stdafx.h"

#include "BinaryTreeChromosome.h"
#include "utils/HeapSort.h"

/**
 * Defines selection and mutation methods for the genetic algorithm toii perform
 */
class BinaryTreeGeneticAlgo
{

private:

/**
 * Specifies what should be the selected amount of top fit members of a
 * generation
 */
unsigned select;

/**
 * Specifies the leaf value (the actual required indicator value) regeneration
 * probability
 */
double leafValueMutationProbability;

/**
 * Specifies the probability to change the sign for comparism two indicator
 * values
 */
double leafValueSignMutationProbability;

/**
 * Specifies the probability to mutate (change) the logical operator for each
 * node
 */
double logicalNodeMutationProbability;

/**
 * Specifies the probability to make a crossover with two chromosomes switching
 * their buy and sell nodes
 */
double crossoverProbability;

/**
 * Specifies the probability to change an indicator for a leaf node
 */
double leafIndicatorMutationProbability;

public:

/**
 * Creates a new instance of BinaryTree genetic algorithm class with given
 * settings
 */
BinaryTreeGeneticAlgo(
        int selectNumber,
        double leafValueMutation,
        double leafValueSignMutation,
        double logicalNodeMutation,
        double leafValueIndicatorMutation,
        double crossover
        );

~BinaryTreeGeneticAlgo();

/**
 * Performs a mutation on a certain node structur
 * following each child nodes recursively
 *
 * @param node Node which should be mutated (also with children)
 */
void Mutate(TreeNode* node);

/**
 * Performs selection of the most fit chromosomes and mutates them into
 * next generation
 *
 * @param newGeneration The target generation which should be populated
 *                      by the most fit from the old one
 *
 * @param oldGeneration The source generation from which the most fit are picked
 *
 * @param heapSort      reference to a heap sort algorithm
 *
 * @param size          thetarget size of a generation
 */
void Select(
        std::vector<BinaryTreeChromosome*>& newGeneration,
        std::vector<BinaryTreeChromosome*>& oldGeneration,
        HeapSort& heapSort,
        unsigned size);

/**
 * Mutates a certain chromosome to the output chromosome
 * @param chromosomeInput  The input generation
 *
 * @param size             The size from which should be picked
 * @param outputChromosome The newly generated chromosome
 */
void Mutate(
        std::vector<BinaryTreeChromosome*>& chromosomeInput,
        unsigned size,
        BinaryTreeChromosome* outputChromosome);

/**
 * Performs a crossover in a certain generation
 * @param generation Vector of chromosomes representing one generation
 */
void Crossover(std::vector<BinaryTreeChromosome*>& generation);

/**
 * Performs crossover with two chromosomes switching their buy and sell
 * nodes
 */
void Crossover(
        BinaryTreeChromosome* left,
        BinaryTreeChromosome* right
        );
};