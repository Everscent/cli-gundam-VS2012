#pragma once

namespace Anaheim
{
	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Collections::Generic;

	/**
	 * ���j���[�o�[�C�c�[���o�[�C�R���e�L�X�g���j���[�̊֘A�t��
	 */
	ref class MenuPair
	{
	/**
	 * �t�B�[���h
	 */
	private:
		ToolStripMenuItem^ mainMenu;		///< ���j���[�o�[
		ToolStripMenuItem^ contextMenu;		///< �R���e�L�X�g���j���[
		ToolStripButton^ toolButton;		///< �c�[���{�^��

	/**
	 * �R���X�g���N�^
	 */
	public:
		MenuPair(ToolStripMenuItem^ mainMenu, ToolStripMenuItem^ contextMenu, ToolStripButton^ toolButton);

	/**
	 * ���\�b�h
	 */
	public:
		/// �y�A�̃��C�����j���[���s
		bool ExecuteMainMenu();
		/// �y�A�̃R���e�L�X�g�C�c�[���o�[��Enabled�ύX
		bool ChangeEnabled(bool enabled);

	/**
	 * �v���p�e�B
	 */
	public:
		/// ���C�����j���[
		property ToolStripMenuItem^ MainMenu
		{
			ToolStripMenuItem^ get() { return this->mainMenu; }
		}
		/// �R���e�L�X�g���j���[
		property ToolStripMenuItem^ ContextMenue
		{
			ToolStripMenuItem^ get() { return this->contextMenu; }
		}
		/// �c�[���{�^��
		property ToolStripButton^ ToolButton
		{
			ToolStripButton^ get() { return this->toolButton; }
		}
	};
	// ----------------------------------------------------------------------------------------------------

	/**
	 * ���j���[�֘A�t�����X�g
	 */
	public ref class MenuPairList
	{
	/**
	 * �t�B�[���h
	 */
	private:
		List<MenuPair^>^ items;

	/**
	 * �R���X�g���N�^
	 */
	public:
		MenuPairList();

	/**
	 * ���\�b�h
	 */
	public:
		/// �o�^�i���C�����j���[�C�R���e�L�X�g���j���[�j
		void SetPair(ToolStripMenuItem^ mainMenu, ToolStripMenuItem^ contextMenu);
		/// �o�^�i���C�����j���[�C�c�[���{�^��
		void SetPair(ToolStripMenuItem^ mainMenu, ToolStripButton^ toolButton);
		/// �o�^�i���C�����j���[�C�R���e�L�X�g���j���[�C�c�[���{�^���j
		void SetPair(ToolStripMenuItem^ mainMenu, ToolStripMenuItem^ contextMenu, ToolStripButton^ toolButton);
		/// �y�A�̃R���e�L�X�g���j���[���s
		bool ExecuteContext(Object^ contextMenu);
		/// �y�A�̃c�[���{�^�����s
		bool ExecuteToolButtont(Object^ toolButton);
		/// �y�A��Enabled�X�V
		bool UpdateEnabled(Object^ mainMenu);
	};
	// ----------------------------------------------------------------------------------------------------
}
