#include "queue.h"
#include "gtest/gtest.h"

class QueueTest : public ::testing::Test
{
protected:
	void SetUp() override
	{
		queueinit(&q);
	}

	void TearDown() override
	{
		queuedestory(&q);
	}

	queue q;
};

TEST_F(QueueTest, InitCreatesEmptyQueue)
{
	EXPECT_TRUE(queueempty(&q));
	EXPECT_EQ(0, queuesize(&q));
	ASSERT_NE(nullptr, q.front);
	EXPECT_EQ(q.front, q.tail);
}

TEST_F(QueueTest, EnqueueSingleElement)
{
	enqueue(&q, 42);
	EXPECT_FALSE(queueempty(&q));
	EXPECT_EQ(1, queuesize(&q));
	EXPECT_EQ(42, queuefront(&q));
}

TEST_F(QueueTest, EnqueueKeepsFifoOrder)
{
	enqueue(&q, 1);
	enqueue(&q, 2);
	enqueue(&q, 3);

	EXPECT_EQ(1, dequeue(&q));
	EXPECT_EQ(2, dequeue(&q));
	EXPECT_EQ(3, dequeue(&q));

	EXPECT_TRUE(queueempty(&q));
	EXPECT_EQ(0, queuesize(&q));
}

TEST_F(QueueTest, QueueFrontDoesNotRemoveElement)
{
	enqueue(&q, 7);
	enqueue(&q, 8);

	EXPECT_EQ(7, queuefront(&q));
	EXPECT_EQ(7, queuefront(&q));
	EXPECT_EQ(2, queuesize(&q));
}

TEST_F(QueueTest, SizeTracksEnqueueAndDequeue)
{
	for (int i = 0; i < 100; ++i)
	{
		enqueue(&q, i);
	}
	EXPECT_EQ(100, queuesize(&q));

	for (int i = 0; i < 100; ++i)
	{
		EXPECT_EQ(i, dequeue(&q));
	}
	EXPECT_EQ(0, queuesize(&q));
	EXPECT_TRUE(queueempty(&q));
}

TEST_F(QueueTest, ReuseQueueAfterEmpty)
{
	enqueue(&q, 1);
	EXPECT_EQ(1, dequeue(&q));

	enqueue(&q, 2);
	EXPECT_EQ(2, queuefront(&q));
	EXPECT_EQ(2, dequeue(&q));
	EXPECT_TRUE(queueempty(&q));
}

TEST(QueueDestoryTest, DestoryResetsQueue)
{
	queue other;
	queueinit(&other);
	enqueue(&other, 1);
	enqueue(&other, 2);
	queuedestory(&other);

	EXPECT_EQ(0, queuesize(&other));
	EXPECT_TRUE(queueempty(&other));
}
