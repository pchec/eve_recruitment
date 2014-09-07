<?php
/**
 * @file
 * Default views of the EVE Recruitment module.
 */


function eve_recruitment_views_default_views() {
	$view = new view();
	$view->name = 'recruitment_statistics';
	$view->description = '';
	$view->tag = 'default';
	$view->base_table = 'eve_recruitment';
	$view->human_name = 'Recruitment Statistics';
	$view->core = 7;
	$view->api_version = '3.0';
	$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

	/* Display: Master */
	$handler = $view->new_display('default', 'Master', 'default');
	$handler->display->display_options['title'] = 'Recruitment Summary';
	$handler->display->display_options['use_more_always'] = FALSE;
	$handler->display->display_options['group_by'] = TRUE;
	$handler->display->display_options['access']['type'] = 'perm';
	$handler->display->display_options['access']['perm'] = 'view statistics';
	$handler->display->display_options['cache']['type'] = 'none';
	$handler->display->display_options['query']['type'] = 'views_query';
	$handler->display->display_options['exposed_form']['type'] = 'basic';
	$handler->display->display_options['pager']['type'] = 'mini';
	$handler->display->display_options['pager']['options']['items_per_page'] = '10';
	$handler->display->display_options['pager']['options']['offset'] = '0';
	$handler->display->display_options['pager']['options']['id'] = '0';
	$handler->display->display_options['style_plugin'] = 'table';
	$handler->display->display_options['style_options']['columns'] = array(
		'name' => 'name',
		'name_1' => 'name_1',
	);
	$handler->display->display_options['style_options']['default'] = 'name_1';
	$handler->display->display_options['style_options']['info'] = array(
		'name' => array(
			'sortable' => 1,
			'default_sort_order' => 'asc',
			'align' => '',
			'separator' => '',
			'empty_column' => 0,
		),
		'name_1' => array(
			'sortable' => 1,
			'default_sort_order' => 'desc',
			'align' => 'views-align-right',
			'separator' => '',
			'empty_column' => 0,
		),
	);
	/* Relationship: Recruitment: Added By */
	$handler->display->display_options['relationships']['added_by']['id'] = 'added_by';
	$handler->display->display_options['relationships']['added_by']['table'] = 'eve_recruitment';
	$handler->display->display_options['relationships']['added_by']['field'] = 'added_by';
	/* Relationship: Recruitment: Mailed By */
	$handler->display->display_options['relationships']['mailed_by']['id'] = 'mailed_by';
	$handler->display->display_options['relationships']['mailed_by']['table'] = 'eve_recruitment';
	$handler->display->display_options['relationships']['mailed_by']['field'] = 'mailed_by';
	/* Field: User: Name */
	$handler->display->display_options['fields']['name']['id'] = 'name';
	$handler->display->display_options['fields']['name']['table'] = 'users';
	$handler->display->display_options['fields']['name']['field'] = 'name';
	$handler->display->display_options['fields']['name']['relationship'] = 'added_by';
	$handler->display->display_options['fields']['name']['label'] = 'Recruiter Name';
	/* Field: COUNT(User: Name) */
	$handler->display->display_options['fields']['name_1']['id'] = 'name_1';
	$handler->display->display_options['fields']['name_1']['table'] = 'users';
	$handler->display->display_options['fields']['name_1']['field'] = 'name';
	$handler->display->display_options['fields']['name_1']['relationship'] = 'added_by';
	$handler->display->display_options['fields']['name_1']['group_type'] = 'count';
	$handler->display->display_options['fields']['name_1']['label'] = 'Names Contributed';
	$handler->display->display_options['fields']['name_1']['separator'] = ' ';

	/* Display: Recruitment Summary */
	$handler = $view->new_display('page', 'Recruitment Summary', 'recruitment_summary');
	$handler->display->display_options['defaults']['header'] = FALSE;
	$handler->display->display_options['path'] = 'recruitment/summary';

	/* Display: Mailing Summary */
	$handler = $view->new_display('attachment', 'Mailing Summary', 'mailing_summary');
	$handler->display->display_options['defaults']['title'] = FALSE;
	$handler->display->display_options['pager']['type'] = 'none';
	$handler->display->display_options['pager']['options']['offset'] = '0';
	$handler->display->display_options['defaults']['fields'] = FALSE;
	/* Field: User: Name */
	$handler->display->display_options['fields']['name']['id'] = 'name';
	$handler->display->display_options['fields']['name']['table'] = 'users';
	$handler->display->display_options['fields']['name']['field'] = 'name';
	$handler->display->display_options['fields']['name']['relationship'] = 'mailed_by';
	$handler->display->display_options['fields']['name']['label'] = 'Recruiter Name';
	/* Field: COUNT(User: Name) */
	$handler->display->display_options['fields']['name_1']['id'] = 'name_1';
	$handler->display->display_options['fields']['name_1']['table'] = 'users';
	$handler->display->display_options['fields']['name_1']['field'] = 'name';
	$handler->display->display_options['fields']['name_1']['relationship'] = 'mailed_by';
	$handler->display->display_options['fields']['name_1']['group_type'] = 'count';
	$handler->display->display_options['fields']['name_1']['label'] = 'People Mailed';
	$handler->display->display_options['fields']['name_1']['separator'] = ' ';
	$handler->display->display_options['defaults']['filter_groups'] = FALSE;
	$handler->display->display_options['defaults']['filters'] = FALSE;
	/* Filter criterion: User: The user ID */
	$handler->display->display_options['filters']['uid_raw']['id'] = 'uid_raw';
	$handler->display->display_options['filters']['uid_raw']['table'] = 'users';
	$handler->display->display_options['filters']['uid_raw']['field'] = 'uid_raw';
	$handler->display->display_options['filters']['uid_raw']['relationship'] = 'mailed_by';
	$handler->display->display_options['filters']['uid_raw']['operator'] = 'not empty';
	$handler->display->display_options['displays'] = array(
		'recruitment_summary' => 'recruitment_summary',
		'default' => 0,
	);
	$handler->display->display_options['attachment_position'] = 'after';
	$translatables['recruitment_statistics'] = array(
		t('Master'),
		t('Recruitment Summary'),
		t('more'),
		t('Apply'),
		t('Reset'),
		t('Sort by'),
		t('Asc'),
		t('Desc'),
		t('Items per page'),
		t('- All -'),
		t('Offset'),
		t('« first'),
		t('‹ previous'),
		t('next ›'),
		t('last »'),
		t('Added By'),
		t('Mailed By'),
		t('Recruiter Name'),
		t('Names Contributed'),
		t('Mailing Summary'),
		t('People Mailed'),
	);
	$views[$view->name] = $view;
	return $views;
}
