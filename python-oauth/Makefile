#
# Copyright (C) 2011-2020 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Abandoned in 2009

include $(TOPDIR)/rules.mk

PKG_NAME:=python-oauth
PKG_VERSION:=1.0.1
PKG_RELEASE:=1

PYPI_NAME:=oauth
PKG_HASH:=e769819ff0b0c043d020246ce1defcaadd65b9c21d244468a45a7f06cb88af5d

#include $(TOPDIR)/feeds/packages/lang/python/pypi.mk
include $(INCLUDE_DIR)/package.mk
#include $(TOPDIR)/feeds/packages/lang/python/python-package.mk

define Package/python-oauth
	SECTION:=lang
	CATEGORY:=Languages
	SUBMENU:=Python
#	DEPENDS:=+python
	TITLE:=Library for OAuth 1.0a
	URL:=http://code.google.com/p/oauth
	MAINTAINER:=Entware team, https://entware.net
	VARIANT:=python
endef

define Package/python-oauth/description
 Library for OAuth version 1.0a.
endef

#$(eval $(call PyPackage,python-oauth))
#$(eval $(call BuildPackage,python-oauth))
