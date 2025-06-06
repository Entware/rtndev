# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2011-2025 Entware
#

include $(TOPDIR)/rules.mk

PKG_NAME:=pureftpd
PKG_VERSION:=1.0.52
PKG_REV:=15246910744807685fe00e1b301bd8e68123ed16
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/jedisct1/pure-ftpd.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=9a43faecbc80b7338618e7da1e9280a5052cb026dd6d6465f1bf98edc7db956f

PKG_BUILD_DEPENDS:=mariadb

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
# see other packages when deps on mariadb
include $(INCLUDE_DIR)/nls.mk

define Package/pureftpd
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=File Transfer
	DEPENDS:=+libsodium +libopenssl +libmysqlclient
	TITLE:=Pure FTP server
	URL:=http://www.pureftpd.org/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/pureftpd/description
 Pure-FTPd is a fast, production-quality, standard-conformant FTP server,
 based upon Troll-FTPd.
endef

CONFIGURE_ARGS += \
	--with-everything \
	--with-virtualchroot \
	--without-capabilities \
	--with-paranoidmsg \
	--with-mysql=$(STAGING_DIR)/opt \
	--with-tls \
	--with-certfile=/opt/etc/ssl/private/pure-ftpd.pem \
	--with-rfc2640

define Package/pureftpd/conffiles
/opt/etc/pure-ftpd.conf
endef

define Package/pureftpd/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/pure-* $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/sbin/pure-* $(1)/opt/sbin
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_CONF) $(PKG_INSTALL_DIR)/opt/etc/pure-* $(1)/opt/etc
	$(INSTALL_BIN) files/S65pureftpd $(1)/opt/etc/init.d
endef

$(eval $(call BuildPackage,pureftpd))
