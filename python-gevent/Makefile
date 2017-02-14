#
# Copyright (C) 2011-2017 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Some newer version suffers form seg.faults, so we sit on this for safety reasons

include $(TOPDIR)/rules.mk

PKG_NAME:=python-gevent
PKG_VERSION:=1.1.2
PKG_RELEASE:=1

PKG_SOURCE:=gevent-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://pypi.python.org/packages/43/8f/cb3224a0e6ab663547f45c10d0651cfd52633fde4283bf68d627084df8cc/
PKG_MD5SUM:=bb32a2f852a4997138014d5007215c6e
PKG_BUILD_DEPENDS:=python
PKG_BUILD_DIR:=$(BUILD_DIR)/gevent-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk
$(call include_mk, python-package.mk)

define Package/python-gevent
	SECTION:=lang
	CATEGORY:=Languages
	SUBMENU:=Python
	DEPENDS:=+python-greenlet
	TITLE:=Python networking library
	URL:=http://www.gevent.org/
	MAINTAINER:=Entware team, http://entware.net
endef

define Package/python-gevent/description
 Gevent is a coroutine-based Python networking library that uses greenlet
 to provide a high-level synchronous API on top of the libevent event loop.
endef

define Build/Configure
	touch $(PKG_BUILD_DIR)/c-ares/{Makefile.in,libcares.pc.in}
	(cd $(PKG_BUILD_DIR)/libev; \
	$(CONFIGURE_VARS) \
	./configure \
		--target=$(GNU_TARGET_NAME) \
		--host=$(GNU_TARGET_NAME) \
		--build=$(GNU_HOST_NAME) \
		--prefix=/opt \
	);
	(cd $(PKG_BUILD_DIR)/c-ares; \
	$(CONFIGURE_VARS) \
	./configure \
		--target=$(GNU_TARGET_NAME) \
		--host=$(GNU_TARGET_NAME) \
		--build=$(GNU_HOST_NAME) \
		--prefix=/opt \
	);
	$(call Build/Configure/Default)
endef

define Build/Compile
	$(call Build/Compile/PyMod,,install --prefix=/opt --root=$(PKG_INSTALL_DIR))
endef

define Package/python-gevent/install
	$(INSTALL_DIR) $(1)$(PYTHON_PKG_DIR)
	$(CP) \
		$(PKG_INSTALL_DIR)$(PYTHON_PKG_DIR)/* \
		$(1)$(PYTHON_PKG_DIR)
endef

$(eval $(call BuildPackage,python-gevent))
