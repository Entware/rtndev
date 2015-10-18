#
# Copyright (C) 2011-2015 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=python-oauth
PKG_VERSION:=1.0.1
PKG_RELEASE:=1

PKG_SOURCE:=oauth-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=http://pypi.python.org/packages/source/o/oauth
PKG_MD5SUM:=30ed3cc8c11d7841a89feab437aabf81

PKG_BUILD_DIR:=$(BUILD_DIR)/oauth-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk
$(call include_mk, python-package.mk)

define Package/python-oauth
	SECTION:=lang
	CATEGORY:=Languages
	SUBMENU:=Python
	DEPENDS:=+python
	TITLE:=Library for OAuth 1.0a
	URL:=http://code.google.com/p/oauth
	MAINTAINER:=Entware team, entware.wl500g.info
endef

define Package/python-oauth/description
 Library for OAuth version 1.0a.
endef

define Build/Compile
	$(call Build/Compile/PyMod,,install \
		--prefix=/opt \
		--root="$(PKG_INSTALL_DIR)" \
	)
endef

define Package/python-oauth/install
	$(INSTALL_DIR) $(1)$(PYTHON_PKG_DIR)
	$(CP) \
		$(PKG_INSTALL_DIR)$(PYTHON_PKG_DIR)/* \
		$(1)$(PYTHON_PKG_DIR)
endef

$(eval $(call BuildPackage,python-oauth))
