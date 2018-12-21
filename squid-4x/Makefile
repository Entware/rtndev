#
# Copyright (C) 2017-2018 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=squid-4x
PKG_VERSION:=4.4
PKG_RELEASE:=1

PKG_LICENSE:=GPL-2.0

PKG_SOURCE:=squid-$(PKG_VERSION).tar.xz
PKG_SOURCE_URL:=http://www.squid-cache.org/Versions/v4
PKG_HASH:=4905e6da7f5574d2583ba36f398bb062a12d51e70d67035078b6e85b09e9ee82

PKG_BUILD_DIR:=$(BUILD_DIR)/squid-$(PKG_VERSION)

PKG_BUILD_PARALLEL:=1
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/squid-4x/Default
  SECTION:=net
  CATEGORY:=Network
  SUBMENU:=Web Servers/Proxies
  URL:=http://www.squid-cache.org/
  MAINTAINER:=Entware team, https://entware.net
endef

define Package/squid-4x
  $(call Package/squid-4x/Default)
  MENU:=1
  DEPENDS:=+libpthread +librt +libltdl +libstdcpp +libatomic
  DEPENDS+= +SQUID_use-gnutls:libgnutls +!SQUID_use-gnutls:libopenssl
  DEPENDS+= +SQUID_with-libcap:libcap
  DEPENDS+= +SQUID_with-nettle:libnettle
  DEPENDS+= +SQUID_with-expat:libexpat
  DEPENDS+= +SQUID_with-libxml2:libxml2
  TITLE:=Full-featured Web caching proxy (Beta)
#  USERID:=squid=137:squid=137
endef

define Package/squid-4x/description
  $(TITLE)
endef

define Package/squid-4x/config
	help
		Squid is a caching proxy for the Web supporting HTTP, HTTPS, FTP, and more.
		It reduces bandwidth and improves response times by caching and reusing
		frequently-requested web pages.
		Run as : $(USERID)
		Version: $(PKG_VERSION)
		Home   : $(URL)
		Maintainer: $(PKG_MAINTAINER)

	source "$(SOURCE)/Config.in"
endef


define Package/squid-4x-mod-cachemgr
  $(call Package/squid-4x/Default)
  DEPENDS:=squid-4x
  TITLE:=Web based proxy manager and reporting tool
endef

CONFIGURE_ARGS += \
	--datadir=/opt/share/squid \
	--libexecdir=/opt/lib/squid \
	--sysconfdir=/opt/etc/squid \
	--disable-arch-native \
	--with-dl \
	--enable-shared \
	--disable-static \
	--config-cache \
	--enable-cache-digests \
	--enable-delay-pools \
	--enable-kill-parent-hack \
	--enable-linux-netfilter \
	--without-netfilter-conntrack \
	--disable-unlinkd \
	--enable-x-accelerator-vary \
	--with-pthreads \
	--enable-ssl \
	--disable-translation \
	--disable-auto-locale \
	--enable-epoll \
	--with-maxfd=2048 \
	--disable-ecap \
	--disable-external-acl-helpers \
	--disable-ident-lookups \
	--without-mit-krb5

CONFIGURE_ARGS += \
	$(if $(CONFIG_SQUID_auth-basic),--enable,--disable)-auth-basic \
	$(if $(CONFIG_SQUID_auth-digest),--enable,--disable)-auth-digest \
	$(if $(CONFIG_SQUID_auth-ntlm),--enable,--disable)-auth-ntlm \
	$(if $(CONFIG_SQUID_auth-negotiate),--enable,--disable)-auth-negotiate \
	$(if $(CONFIG_SQUID_enable-ipv6),--enable,--disable)-dlmalloc \
	$(if $(CONFIG_SQUID_enable-ipv6),--enable,--disable)-ipv6 \
	$(if $(CONFIG_SQUID_enable-ssl-crtd),--enable-ssl-crtd) \
	$(if $(CONFIG_SQUID_use-gnutls),--with,--without)-gnutls \
	$(if $(CONFIG_SQUID_use-gnutls),--without-openssl) \
	$(if $(CONFIG_SQUID_use-gnutls),,--with-openssl="$(STAGING_DIR)/opt") \
	$(if $(CONFIG_SQUID_enable-icmp),--enable,--disable)-icmp \
	$(if $(CONFIG_SQUID_enable-icap-client),--enable,--disable)-icap-client \
	$(if $(CONFIG_SQUID_enable-snmp),--enable,--disable)-snmp \
	$(if $(CONFIG_SQUID_with-libcap),--with,--without)-libcap \
	$(if $(CONFIG_SQUID_with-nettle),--with,--without)-nettle \
	$(if $(CONFIG_SQUID_with-expat),--with,--without)-expat \
	$(if $(CONFIG_SQUID_with-libxml2),--with,--without)-libxml2

CONFIGURE_VARS += \
	ac_cv_header_linux_netfilter_ipv4_h=yes

define Build/Compile
	+$(MAKE) $(PKG_JOBS) -C $(PKG_BUILD_DIR)/lib all
	+$(MAKE) $(PKG_JOBS) -C $(PKG_BUILD_DIR) \
		DESTDIR="$(PKG_INSTALL_DIR)" \
		install
endef

define Package/squid-4x/install
	$(INSTALL_DIR) $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/sbin/squid $(1)/opt/sbin/
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/* $(1)/opt/sbin/

	$(INSTALL_DIR) $(1)/opt/lib/squid
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/lib/squid/* $(1)/opt/lib/squid

	$(INSTALL_DIR) $(1)/opt/etc/squid
	$(CP) $(PKG_INSTALL_DIR)/opt/etc/squid/* $(1)/opt/etc/squid/
	$(CP) ./files/squid.conf $(1)/opt/etc/squid/

	$(INSTALL_DIR) $(1)/opt/etc/init.d/
	$(INSTALL_BIN) ./files/S22squid4 $(1)/opt/etc/init.d/

	$(INSTALL_DIR) $(1)/opt/share/squid/
	$(INSTALL_DIR) $(1)/opt/share/squid/icons/
	$(INSTALL_DIR) $(1)/opt/share/squid/errors/templates/
	$(CP) $(PKG_INSTALL_DIR)/opt/share/squid/mib.txt $(1)/opt/share/squid/
	$(CP) $(PKG_INSTALL_DIR)/opt/share/squid/icons/* $(1)/opt/share/squid/icons/
	$(CP) \
		$(PKG_INSTALL_DIR)/opt/share/squid/errors/templates/* \
		$(1)/opt/share/squid/errors/templates/
	# fix perl exec path in scripts
	$(SED) '1c\#!/opt/bin/perl' $(1)/opt/lib/squid/helper-mux
	$(SED) '1c\#!/opt/bin/perl' $(1)/opt/lib/squid/log_db_daemon
	$(SED) '1c\#!/opt/bin/perl' $(1)/opt/lib/squid/security_fake_certverify
	$(SED) '1c\#!/opt/bin/perl' $(1)/opt/lib/squid/storeid_file_rewrite
	$(SED) '1c\#!/opt/bin/perl' $(1)/opt/lib/squid/url_lfs_rewrite

endef

define Package/squid-4x-mod-cachemgr/install
	$(INSTALL_DIR) $(1)/opt/share/www/cgi-bin/
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/squid/cachemgr.cgi $(1)/opt/share/www/cgi-bin/
endef

$(eval $(call BuildPackage,squid-4x))
$(eval $(call BuildPackage,squid-4x-mod-cachemgr))
