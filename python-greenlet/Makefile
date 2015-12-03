#
# Copyright (C) 2011-2015 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=python-greenlet
PKG_VERSION:=0.4.9
PKG_RELEASE:=1

PKG_SOURCE:=greenlet-$(PKG_VERSION).zip
PKG_SOURCE_URL:=http://pypi.python.org/packages/source/g/greenlet
PKG_MD5SUM:=c6659cdb2a5e591723e629d2eef22e82

PKG_BUILD_DEPENDS:=python
PKG_BUILD_DIR:=$(BUILD_DIR)/greenlet-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk
$(call include_mk, python-package.mk)

define Package/python-greenlet
	SECTION:=lang
	CATEGORY:=Languages
	SUBMENU:=Python
	DEPENDS:=+python
	TITLE:=lightweight in-process concurrent programming
	URL:=https://pypi.python.org/pypi/greenlet
	MAINTAINER:=Entware team, entware.wl500g.info
endef

define Package/python-greenlet/description
 Lightweight in-process concurrent programming.
endef

define Build/Compile
	$(call Build/Compile/PyMod,,install --prefix=/opt --root=$(PKG_INSTALL_DIR))
endef

define Package/python-greenlet/install
	$(INSTALL_DIR) $(1)$(PYTHON_PKG_DIR)
	$(CP) \
		$(PKG_INSTALL_DIR)$(PYTHON_PKG_DIR)/* \
		$(1)$(PYTHON_PKG_DIR)
	$(INSTALL_DIR) $(1)/opt/include/python2.7/greenlet
	$(INSTALL_DATA) $(PKG_INSTALL_DIR)/opt/include/python2.7/greenlet/greenlet.h \
		$(1)/opt/include/python2.7/greenlet
endef

$(eval $(call BuildPackage,python-greenlet))
