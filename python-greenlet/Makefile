#
# Copyright (C) 2011-2018 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=python-greenlet
PKG_VERSION:=0.4.13
PKG_RELEASE:=1

PKG_SOURCE:=greenlet-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://pypi.python.org/packages/13/de/ba92335e9e76040ca7274224942282a80d54f85e342a5e33c5277c7f87eb
PKG_HASH:=0fef83d43bf87a5196c91e73cb9772f945a4caaff91242766c5916d1dd1381e4

PKG_BUILD_DEPENDS:=python
PKG_BUILD_DIR:=$(BUILD_DIR)/greenlet-$(PKG_VERSION)

PKG_UNPACK=$(HOST_TAR) -C $(PKG_BUILD_DIR) --strip-components=1 -xf $(DL_DIR)/$(PKG_SOURCE)

include $(INCLUDE_DIR)/package.mk
include $(TOPDIR)/feeds/packages/lang/python/python-package.mk

define Package/python-greenlet
	SECTION:=lang
	CATEGORY:=Languages
	SUBMENU:=Python
	DEPENDS:=+python
	TITLE:=lightweight in-process concurrent programming
	URL:=https://pypi.python.org/pypi/greenlet
	MAINTAINER:=Entware team, https://entware.net
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
