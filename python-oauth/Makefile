#
# Copyright (C) 2011-2018 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Abandoned in 2009

include $(TOPDIR)/rules.mk

PKG_NAME:=python-oauth
PKG_VERSION:=1.0.1
PKG_RELEASE:=1

PKG_SOURCE:=oauth-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=http://pypi.python.org/packages/source/o/oauth
PKG_HASH:=e769819ff0b0c043d020246ce1defcaadd65b9c21d244468a45a7f06cb88af5d

PKG_BUILD_DIR:=$(BUILD_DIR)/oauth-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk
include $(TOPDIR)/feeds/packages/lang/python/python-package.mk

define Package/python-oauth
	SECTION:=lang
	CATEGORY:=Languages
	SUBMENU:=Python
	DEPENDS:=+python
	TITLE:=Library for OAuth 1.0a
	URL:=http://code.google.com/p/oauth
	MAINTAINER:=Entware team, https://entware.net
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
